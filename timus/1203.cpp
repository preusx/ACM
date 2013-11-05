#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Comparator {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second == b.second ?
			a.first < b.first :
			a.second < b.second;
	}
};

int main() {
	int n, a, b;
	vector< pair<int, int> > segments;
	pair<int, int> current;

	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		segments.push_back(make_pair(a, b));
	}

	sort(segments.begin(), segments.end(), Comparator());

	n = 1;

	current = segments[0];
	for(vector< pair<int, int> >::iterator it = segments.begin();\
		it != segments.end(); it++) {
		// printf("\t%d %d\n", it->first, it->second);
		if(current.second < it->first) {
			// printf("\t\t%d %d\n", it->first, it->second);
			n++;
			current = *it;
		}
	}

	printf("%d\n", n);

	return 0;
}