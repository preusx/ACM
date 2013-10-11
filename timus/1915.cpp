#include <stdio.h>

#include <vector>
// #include <algorithm>

using namespace std;

int main() {
	int n, x, csize, i, j;
	vector <int> a;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &x);

		if(x > 0) {
			a.push_back(x);
		// } else if(x == 0) {
		// 	csize = a.size();

		// 	if(csize < 1000000-i+1) {
		// 		for(j = 0; j < csize; j++) {
		// 			a.push_back(a[j]);
		// 		}
		// 		// a.insert(a.end(), a.begin(), a.end());
		// 	}
		} else {
			printf("%d\n", a.back());
			a.pop_back();
		}
	}

	return 0;
}