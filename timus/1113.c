#include <stdio.h>

int main() {
	int n, m, f = 0;

	scanf("%d %d", &n, &m);

	if(n <= m) {
		printf("%d\n", n);
		return 0;
	}

	// f += m/3 + 1;

	while(true) {
		f += m;
		if(n <= m) {
			break;
		}
		m += m/3 + 1;
	}

	// f += m/3 + 1;

	printf("%d\n", f);

	return 0;
}