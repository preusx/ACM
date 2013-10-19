#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, b;
    char bb[3];
    vector <int> a;

    scanf("%d", &c);

    for(int i = 0; i < c; i++) {
        scanf("%d", &b);
        a.push_back(b);
    }

    sort(a.begin(), a.end());

    scanf("%s", &bb);

    scanf("%d", &c);

    for(int i = 0; i < c; i++) {
        scanf("%d", &b);
        printf("%d\n", a[b-1]);
    }

    return 0;
}
