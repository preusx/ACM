#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <math.h>

using namespace std;

#define DT double
#define _for(i, from, to) for(DT i = (from); i < (to); i++)

int main() {
	DT number;
	stack<DT> numbers;

	// freopen("input.txt", "r", stdin);

	while(scanf("%lf", &number) != EOF) {
		numbers.push(sqrt(number));
	}

	while(!numbers.empty()) {
		printf("%.4lf\n", numbers.top());
		numbers.pop();
	}

	// fclose(stdin);

	return 0;
}