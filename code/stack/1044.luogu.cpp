#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f(i) * f(n - i - 1);
    }
    return ans;
}


int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
        
    
    return 0;
}
