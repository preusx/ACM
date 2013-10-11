#include <stdio.h>
#include <stdlib.h>

#include <map>
// #include <algorithm>

#define DT long long
#define pb push_back

using namespace std;

int main() {
	int n, p, b, i,
		coins = 0, ccj = 0,
		ccoins = 0,
		spells = 0;
	map<int, int> a;
	map<int, int>::iterator j;

	scanf("%d %d", &n, &p);

	for(i = 0; i < n; i++) {
		scanf("%d", &b);
		a[b]++;
	}

	// sort(a.begin(), a.end());

	for(j = a.begin(); j != a.end(); j++) {
		if(j->first*j->second <= p) {
			if(j->first*(j->second+ccoins) > p) {
				if(ccj <= p && ccoins != 0 && ccj != 0) {
					spells++;
					coins += ccoins;
				}
				ccoins = j->second;
			} else {
				ccoins += j->second;
			}
			ccj = j->first * ccoins;
		} else {
			break;
		}
	}

	if(ccj <= p && ccoins != 0 && ccj != 0) {
		coins += ccoins;
		spells++;
	}

	printf("%d %d\n", coins, spells);

	return 0;
}