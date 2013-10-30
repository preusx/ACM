#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int kadane2d(int **a, int n, int m) {
	int sum = INT_MIN, bsum = INT_MIN, temp,
		row, i, j, *columnSum;

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

				if(temp > bsum) {
					bsum = temp;
				}
				if(temp < 0) {
					temp = 0;
				}
			}

			if(bsum > sum) {
				sum = bsum;
			}
		}
	}

	free(columnSum);

	return sum;
}

int main() {
	int n, i, j, **a;

	scanf("%d", &n);

	a = (int **)malloc(sizeof(int*)*n);

	for(i = 0; i < n; i++) {
		a[i] = (int *)malloc(sizeof(int)*n);

		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d\n", kadane2d(a, n, n));

	return 0;
}