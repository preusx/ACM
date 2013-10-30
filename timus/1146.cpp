#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <vector>
#include <map>

using namespace std;

vector< pair<int, int> > kadane2d(int **a, int n, int m) {
	int sum = INT_MIN, bsum = INT_MIN, temp,
		row, i, j, *columnSum;

	vector< pair<int, int> > coords, tcoords, c;

	columnSum = (int *)malloc(sizeof(int)*n);

	for(row = 0; row < m; row++) {
		for(i = 0; i < n; i++) {
			columnSum[i] = 0;
		}

		for(i = row; i < m; i++) {
			bsum = INT_MIN;
			temp = 0;

			for(j = 0; j < n; j++) {
				columnSum[j] += a[i][j];
				temp += columnSum[j];
				tcoords.push_back(make_pair(i, j));

				if(temp > bsum) {
					bsum = temp;
					coords = tcoords;
				}
				if(temp < 0) {
					temp = 0;
					tcoords.resize(0);
				}
			}

			if(bsum > sum) {
				sum = bsum;
				c = coords;
			}
		}
	}

	free(columnSum);

	return c;
}

int main() {
	int n, i, j, **a;
	vector< pair<int, int> > coords;

	scanf("%d", &n);

	a = (int **)malloc(sizeof(int*)*n);

	for(i = 0; i < n; i++) {
		a[i] = (int *)malloc(sizeof(int)*n);

		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	coords = kadane2d(a, n, n);

	for(vector< pair<int, int> >::iterator it = coords.begin();\
		it != coords.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}

	return 0;
}