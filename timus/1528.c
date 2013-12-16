#include <stdio.h>

int main() {
    long long n, p, i, j,
        f[10002] = {0},
        g[10002] = {0};

    f[1] = 1; g[1] = 1;

    for(i = 2; i < 10001; i++) {
        g[i] = 1;
        for(j = 1; j < i; j++) {
            g[i] += 2 * g[j];
        }
        g[i] -= g[i-1] * g[i-1];
    }

    for(i = 2; i < 10001; i++) {
        f[i] = 1;
        for(j = 1; j < i; j++) {
            f[i] +=  f[j] * g[j];
        }
    }

    // for(i = 2; i < 10; i++) {
    //     printf("%ld ", f[i]);
    // }

    for(;;) {
        scanf("%lld %lld", &n, &p);

        if(n == 0 && p == 0) break;

        printf("%lld\n", f[n] % p);
    }

    return 0;
}