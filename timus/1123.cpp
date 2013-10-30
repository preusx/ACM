#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

int main() {
	string a;
	int m, n, l, i;

	cin >> a;

	l = a.length();
	m = (l >> 1) - 1;
	n = l - m - 1;

	// printf("%d\n", m);

	if(a[m] < a[n]) {
		a[m]++;

		if(l%2) {
			a[m+1] = '0';
		}
	}

	for(i = 0; i <= m; i++) {
		printf("%c", a[i]);
	}

	if(l%2) {
		printf("%c", a[m+1]);
	}

	for(i = m; i >= 0; i--) {
		printf("%c", a[i]);
	}

	printf("\n");

	return 0;
}