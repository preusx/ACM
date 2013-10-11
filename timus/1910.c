#include <stdio.h>

int main() {
	int sum = 0, position, ns[3] = {0}, n, i;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &ns[i%3]);

		if(ns[0] + ns[1] + ns[2] > sum) {
			sum = ns[0] + ns[1] + ns[2];
			position = i;
		}
	}

	printf("%d %d\n", sum, position);

	return 0;
}