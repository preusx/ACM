#include <stdio.h>

int main() {
    char buf;
    // freopen("input.txt", )
    printf("/*C*/\n#include <stdio.h>\nint main(){printf(\"");
    while(scanf("%c", &buf) != -1) {
        if(buf == '\\' || buf == '"')
            printf("\\%c", buf);
        else
            printf("%c", buf);
    }
    printf("\";return 0;}");
}