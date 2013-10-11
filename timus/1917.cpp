#include <stdio.h>
#include <stdlib.h>

#include <map>
// #include <algorithm>

#define DT long long
#define pb push_back

using namespace std;

int main() {
	int n, p, b, i,
		coins = 0,
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
		ccoins += j->second;
		
		if((long long)ccoins*j->first > p) {
			if(ccoins - j->second > 0) {
				coins += ccoins - j->second;
				spells++;
			} else {
				j++;
			}

			ccoins = 0;
			j--;
		} else if((long long)ccoins*j->first == p) {
			coins += ccoins;
			spells++;
			ccoins = 0;
		}
	}

	printf("%d %d\n", coins, spells);

	return 0;
}