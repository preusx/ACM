#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, s;

    scanf("%d", &n);
    s = (int)sqrt(n) + 1;

    int a[n+1], b[s+1];

    for(i = 0; i <= n; i++) {
        a[i] = i;
    }
    for(i = 1; i <= s; i++) {
        b[i] = i*i;
    }

    for(i = 1; i <= s; i++) {
        for(j = 0; j+b[i] <= n; j++) {
            if(a[j+b[i]] > a[j] + 1) {
                a[j+b[i]] = a[j] + 1;
            }
        }
    }

    printf("%d\n", a[n]);
}