#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>

#define max_n 900

int main() {
    char User[10];
    int fd;
    struct sockaddr_in server_addr;
    socklen_t server_len;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    memset(User, 0, sizeof(User));
    User[0]='C';
    User[1]='t';
    User[2]='h';
    User[3]='u';
    User[4]='l';
    User[5]='h';
    User[6]='u';
    User[7]='\0';
    int User_size=strlen(User) + 1;


    fd = socket(AF_INET, SOCK_STREAM, 0);
 
    server_addr.sin_port = htons(8731);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.40");
    server_len = sizeof(server_addr);

    if (connect(fd, (struct sockaddr *)&server_addr, server_len) < 0) {
	printf("ERROR\n");
    }
    printf("connected\n");
    int i = send(fd, User, User_size, 0);
    if ( i < 0 ) {
	printf("error \n");
    }



    char buf[max_n];
    memset(buf, 0, sizeof(buf));
    while (scanf("%s", buf) != EOF) {

	send(fd, buf, strlen(buf), 0);
	memset(buf, 0, sizeof(buf));
    }
    close(fd);
    return 0;
}
