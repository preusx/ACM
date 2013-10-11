#include <stdio.h>

int len(char *string) {
	int count = 0;

	while(*string != '\0') {
		count++;
		string++;
	}

	return count;
}

int main() {
	char a[100000], b[100000];

	scanf("%s %s", &a, &b);

	printf("%d %d", len(a), len(b));

	return 0;
}