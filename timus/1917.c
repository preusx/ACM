#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sort_larger(int first, int last) {
	return first > last;
}

void merge(int *main, int *begin, int *split, int *end) {
	int *temp = (int*)malloc(sizeof(int)*(end-begin+1)),
		*pos1 = begin,
		*pos2 = split;

	while(pos1 < split && pos2 <= end) {
		if(sort_larger(*pos1, *pos2)) {
			*temp = *pos1;
			pos1++;
		} else {
			*temp = *pos2;
			pos2++;
		}

		temp++;
	}

	while(pos1 < split) {
		*temp = *pos1;
		pos1++;
	}

	while(pos2 <= end) {
		*temp = *pos2;
		pos2++;
	}
	temp -= end-begin;

	while(begin <= end) {
		*begin = *temp;
		begin++;
		temp++;
	}
	temp -= end-begin;
	// free(temp);
}

void mergeSort(int *main, int *begin, int *end) {
	int *split;

	if(end > begin) {
		split = begin + ((end - begin) >> 1);

		mergeSort(main, begin, split);
		mergeSort(main, split+1, end);
		merge(main, begin, split, end);
	}
}

int main() {
	int n, p, a[10000], i;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	mergeSort(a, a, a+n);

	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	// for(i = 0; i < n; i++) {
	// 	if(c < buf) {
	// 		ccount++;
	// 	} else {
	// 		ccount = i > 0 ? 1 : 0;
	// 		ci = i;
	// 		c = buf;
	// 	}

	// 	if(bcount < ccount) {
	// 		bcount = ccount;
	// 		bi = ci;
	// 	}
	// }

	// printf("%d", bi+1);

	return 0;
}