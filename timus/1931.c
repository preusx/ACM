#include <stdio.h>

int main() {
	long c = 100000000000, buf;
	int n, i,
		bi = 0, bcount = 0,
		ci = 0, ccount = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%ld", &buf);

		if(c < buf) {
			ccount++;
		} else {
			ccount = i > 0 ? 1 : 0;
			ci = i;
			c = buf;
		}

		if(bcount < ccount) {
			bcount = ccount;
			bi = ci;
		}
	}

	printf("%d", bi+1);

	return 0;
}