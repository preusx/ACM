#include <stdio.h>

#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    int n, m, despare[2] = {0}, min, b;

    scanf("%d %d", &n, &m);

    int nn[n], mm[m];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nn[i]);
        despare[0] += nn[i];
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &mm[i]);
        despare[1] += mm[i];
    }

    sort(nn, nn+n, comp);
    sort(mm, mm+m, comp);

    min = despare[0];

    for(int i = 0; i < (n > m ? m : n); i++) {
        despare[0] -= nn[i];
        despare[1] -= mm[i];
        b = despare[0]+(despare[1] * (i+1));
        if(b < min) {
            min = b;
        }
    }

    printf("%d\n", min);
    return 0;
}