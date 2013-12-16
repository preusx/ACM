#include <stdio.h>

int main() {
    int n, l, k;

    scanf("%d %d %d", &n, &k, &l);

    printf("%.4f %.4f\n", (float)(n/k*l), (float)(n/k*l+(n%k>0?l:0)));
    return 0;
}