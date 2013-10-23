#include <stdio.h>
#include <math.h>

#include <vector>
#include <stack>
#include <map>

using namespace std;

const float MAX = 1000000000;

struct To {
	int x, y;
	float cost;
};

struct Node {
	float cost;
	vector<To*> to;
};

int n, m;

To *create_to(int x, int y, float cost) {
	To *t = new To;
	t->x = x;
	t->y = y;
	t->cost = cost;

	return t;
}

Node *create(int x, int y) {
	Node *nn = new Node;
	if(x < n) {
		nn->to.push_back(create_to(x+1, y, 100));
	}
	if(y < m) {
		nn->to.push_back(create_to(x, y+1, 100));
	}
	nn->cost = MAX;

	return nn;
}

int main() {
	int k, x, y, i, j;
	stack< pair<int, int> > way;
	pair<int, int> current;
	vector<To*>::iterator it;

	scanf("%d %d %d", &n, &m, &k);

	vector< vector<Node*> > a(n+1);

	for(i = 0; i <= n; i++) {
		// a[i].resize(m+1, NULL);
		for(j = 0; j <= m; j++) {
			a[i].push_back(create(i, j));
		}
	}

	for(i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);

		a[x-1][y-1]->to.push_back(create_to(x, y, 141.421356));
	}
	a[0][0]->cost = 0;

	way.push(make_pair(0, 0));

	while(!way.empty()) {
		current = way.top();
		way.pop();

		for(it = a[current.first][current.second]->to.begin();\
			it != a[current.first][current.second]->to.end(); it++) {
			if(a[(*it)->x][(*it)->y]->cost >\
				a[current.first][current.second]->cost + (*it)->cost) {
				a[(*it)->x][(*it)->y]->cost =\
					a[current.first][current.second]->cost + (*it)->cost;
				way.push(make_pair((*it)->x, (*it)->y));
			}
		}
	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= m; ++j)
	// 	{
	// 		printf("%f ", a[i][j]->cost);
	// 	}
	// 	printf("\n");
	// }

	printf("%d", lround(a[n][m]->cost));

	return 0;
}