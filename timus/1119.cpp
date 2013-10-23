#include <stdio.h>
#include <math.h>

#include <vector>
#include <stack>
#include <map>

using namespace std;

const float MAX = 1000000000;

int main() {
	float kk;
	stack< pair<int, int> > went;
	pair<int, int> current;
	int n, m, k, x, y, i, j;

	scanf("%d %d %d", &n, &m, &k);

	vector< vector<float> > a(n+1);
	vector< vector<bool> > c(n+1);

	for (i = 0; i <= n; ++i) {
		a[i].resize(m+1, MAX);
	}

	for (i = 0; i <= n; ++i) {
		c[i].resize(m+1, false);
	}

	for(i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		c[x][y] = true;
	}

	a[0][0] = 0;

	went.push(make_pair(0, 0));

	while(!went.empty()) {
		current = went.top();
		went.pop();
		// printf("\t%d %d\n", current.first, current.second);	

		int b[3][2] = {
			{current.first+1, current.second},
			{current.first, current.second+1},
			{current.first+1, current.second+1}
		};
		
		for(i = 0; i < 3; i++) {
			if(b[i][0] <= n && b[i][1] <= m) {
				if(i == 2) {
					if(c[b[i][0]][b[i][1]]) {
						kk = 141.42135623;
					} else {
						kk = -1;
					}
				} else {
					kk = 100;
				}

				if(kk > 0) {
					if(a[b[i][0]][b[i][1]] > a[current.first][current.second] + kk) {
						a[b[i][0]][b[i][1]] = a[current.first][current.second] + kk;
						went.push(make_pair(b[i][0], b[i][1]));
					}
				}
			}
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		printf("%f ", a[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", lround(a[n][m]));

	return 0;
}

