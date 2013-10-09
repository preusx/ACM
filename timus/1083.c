#include <stdio.h>

int main() {
	int k = 0, n, f = 1;
	char c;

	scanf("%d", &n);

	while (scanf("%c", &c) != EOF) {
		if (c == '!') {
			// for(k = k+1; k < n; k++) {
			// 	f *= k;
			// }

			// n = f;
			k++;
		}
	}

	for(; n > 0; n -= k) {
		f *= n;
	}

	printf("%d\n", f);

	return 0;
}