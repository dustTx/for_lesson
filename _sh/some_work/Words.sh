#!/bin/sh
length=(0 0 0)
string=(0 0 0)
file=(0 0 0)

filter_conf=./filter.conf

function filter() {
    file_type=`basename $1 | tr [.] "\n" | tail -1`
    grep -w ${file_type} ${filter_conf} 
}

function find_in_file() {
    file $1 | grep text 2>&1 >/dev/null
    if [[ $? -ne 0 ]]; then
	return 
    fi
    words=`cat $1 | tr -c [a-z][A-Z][0-9][_] "\n"`
    for i in $words; do
	temp=${#i}
	if [[ $temp -ge ${length[0]} ]]; then
	    length[2]=${length[1]}
	    string[2]=${string[1]}
	    file[2]=${file[1]}
            length[1]=${length[0]}
	    string[1]=${string[0]}
	    file[1]=${file[0]}
	    length[0]=$temp
	    string[0]=$i
	    file[0]=$1
	    continue
	fi
	if [[ $temp -ge ${length[1]} ]]; then
	    length[2]=${length[1]}
	    string[2]=${string[1]}
	    file[2]=${file[1]}
	    length[1]=$temp
	    string[1]=$i
	    file[1]=$1
	    continue
	fi
	if [[ $temp -ge ${length[0]} ]]; then
	    length[2]=$temp
	    string[2]=$i
	    file[2]=$1
	fi
    done
}


function find_in_dir() {
    for i in `ls -A $1`; do
	if [[ -f $1/$i ]]; then
	    filter $1/$i
	    if [[ $? -eq 0 ]]; then
	      continue
	    fi
	    find_in_file $1/$i
	elif [[ -d $1/$i ]]; then
	    find_in_dir $1/$i
	fi
    done
}

if [[ $# -ne 1 ]]; then
    echo "Usage: Words.sh file_or_dir!"
    exit
fi

if [[ -d $1 ]]; then
    find_in_dir $1
elif [[ -f $1 ]]; then
    find_in_file $1
else
    echo "Error in $1!"
    exit
fi

echo "1 ${string[0]} ${length[0]} ${file[0]}:`grep -w ${string[0]} -n ${file[0]} | cut -d ":" -f 1`"
echo "2 ${string[1]} ${length[1]} ${file[1]}:`grep -w ${string[1]} -n ${file[1]} | cut -d ":" -f 1`"
echo "3 ${string[2]} ${length[2]} ${file[2]}:`grep -w ${string[2]} -n ${file[2]} | cut -d ":" -f 1`"

