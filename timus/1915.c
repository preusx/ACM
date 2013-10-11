#include <stdio.h>

// #include <vector>
// #include <algorithm>

// using namespace std;

int n, x, size, front = 0, i, j;
int a[1000000] = {0};

int front() {}

int main() {

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &x);

		if(x > 0) {
			a[front] = x;
			front = front%1000000 + 1;
			size = size%1000000 + 1;
		// } else if(x == 0) {
		// 	csize = a.size();

		// 	if(csize < 1000000-i+1) {
		// 		for(j = 0; j < csize; j++) {
		// 			a.push_back(a[j]);
		// 		}
		// 		// a.insert(a.end(), a.begin(), a.end());
		// 	}
		} else {
			printf("%d\n", a[front]);
			front--;

			if(front == 0) {
				front = size;
			}
		}
	}

	return 0;
}