#include <stdio.h>
#include <math.h>

int main() {
    char buf, a[1000001] = {0};
    int i, b, count = 0, pos,
        p[6] = {-1, -1, -1, -1, -1, -1};

    while(scanf("%c", &buf) != -1) {
        b = buf - '0';
        if(b >= 0 && b <= 9) {
            pos = count%6;
            p[pos] = b;
            a[p[pos]] = 1;
            // printf("%d %d\n", p[pos], pos);
            for(i = 0; i < 6; i++) {
                // printf("\t%d\n", i);
                if(i != pos && p[i] >= 0) {
                    p[i] *= 10;
                    p[i] += b;
                    a[p[i]] = 1;
                }
                // printf("\t%d\n", p[i]);
            }
            count++;
        }
    }

    for(i = 1; i < 1000001; i++) {
        if(!a[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}