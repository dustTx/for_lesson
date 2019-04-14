#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>


using namespace std;
#define MAX_N 2000000
int q[MAX_N + 5], head = 0, tail = 0;
int ind[MAX_N + 5] = {0};

int main() {
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        printf("%d\n", q[head]);
        scanf("%d", &a);
        while (tail - head && i - ind[head] >= m) head++;
        while (tail - head && q[tail - 1] > a) tail--;
        q[tail] = a;
        ind[tail] = i;
        tail++;
    }
    
    return 0;
}
