#include <stdio.h>

int main() {
    int s, i, j, k;
    long long int a[11][82];

    scanf("%d", &s);
    
    if(s == 1) {
        printf("10\n");
        return 0;
    }

    for(i = 0; i <= 9; i++) {
        for(j = 0; j <= 81; j++) {
            a[i][j] = 0;

            if(i == 1) {
                a[i][j] = 1;
            }
        }
        a[i][1] = i;
        a[i][0] = 1;
    }

    for(i = 2; i <= 9; i++) {
        for(j = 2; j <= s; j++) {
            for(k = 1; k <= i; k++) {
                a[i][j] += a[k][j-1];
            }

            // if(j >= 10) {
            //     a[i][j] -= a[i][j/10];
            // }
        }
    }

    for(i = 1; i <= 9; i++) {
        for(j = 1; j <= s; j++) {
            printf("%6d ", a[i][j]);
        }
        printf("\n");
    }

    // for(i = 0; i <= s; i++) {
    //     printf("%lld\n", s < 9 ? a[9][i] : (long long)(a[9][i] - (long long)(a[9][i-10] * 9)));
    //     printf("\t%lld %lld\n", a[9][i], a[9][i-10] * 9);
    // }

    k = a[9][s];
    if(s >= 9) {
        k += a[9][s-10] * 9 * (s/10%2 ? -1 : 1);

        // if(s >= 18) {
        //     k += a[9][s-18] + 1;
        //     printf("%d ", a[9][s-18]);
        // }
    }

    printf("%lld\n", k);

    return 0;
} 