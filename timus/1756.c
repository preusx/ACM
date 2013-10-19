#include <stdio.h>

int main() {
    int n, a, b, i, p;

    scanf("%d %d %d", &n, &a, &b);
    n *= a;
    if(n > b) {
        p = n % b;
        n = n / b;
        a = n + 1;
    } else {
        p = n;
        n = 0;
        a = 1;
    }

    // printf("%d %d %d\n", n, a, p);

    for(i = 0; i < b; i++) {
        if(i >= p){
            printf("%d ", n);
        } else {
            printf("%d ", a);
        }
    }
    printf("\n");
}
