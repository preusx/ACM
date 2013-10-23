	#include <stdio.h>
	#include <stdlib.h>

	typedef struct {
		int pos, t;
	} Time;

	typedef struct {
		int when, len;
		Time *to[500];
	} Node;

	typedef struct {
		int front, back, a[100000000];
	} Stack;

	Time *t_create(int pos, int tt) {
		Time *t = (Time *)malloc(sizeof(Time));
		t->pos = pos;
		t->t = tt;

		return t;
	}

	Node *n_create() {
		Node *n = (Node *)malloc(sizeof(Node));
		n->when = 500;
		n->len = 0;

		return n;
	}

	Stack *s_create() {
		Stack *a = (Stack *)malloc(sizeof(Stack));
		a->front = 0;
		a->back = 0;

		return a;
	}


	void insert(Node *g, int pos, int t) {
		g->to[g->len] = t_create(pos, t);
		g->len++;
	}

	void push(Stack *s, int ss) {
		s->a[s->front] = ss;
		s->front++;
	}

	int pop(Stack *s) {
		if(s->back == s->front) {
			return -1;
		}

		s->back++;
		return s->a[s->back-1];
	}

	void dfs(Node *graph[], Stack *stack) {
		int pos, i, to;

		while((pos = pop(stack)) != -1) {
			for(i = 0; i < graph[pos]->len; i++) {
				to = graph[pos]->when + graph[pos]->to[i]->t;

				if(graph[graph[pos]->to[i]->pos]->when > to) {
					graph[graph[pos]->to[i]->pos]->when = to;
					push(stack, graph[pos]->to[i]->pos);
				}
			}
		}
	}

	int main() {
		Stack *stack = s_create();
		Node *graph[500] = {NULL};
		int n, m, k, a, b, t, i,
			p[500] = {0};

		scanf("%d %d %d", &n, &m, &k);

		for(i = 0; i < m; i++) {
			scanf("%d", &p[i]);
		}

		for(i = 0; i < k; i++) {
			scanf("%d %d %d", &a, &b, &t);

			if(graph[a] == NULL) {
				graph[a] = n_create();
			}
			if(graph[b] == NULL) {
				graph[b] = n_create();
			}

			insert(graph[a], b, t);
			insert(graph[b], a, t);
		}

		scanf("%d", &a);
		graph[a]->when = 0;
		push(stack, a);

		dfs(graph, stack);

		a = -1;
		for(i = 0; i < m; i++) {
			if(graph[p[i]]->when > a) {
				a = graph[p[i]]->when;
			}
		}

		if(a >= 0) {
			printf("The good sponsor!\n%d\n", a);
		} else {
			printf("It is not fault of sponsor...");
		}

		return 0;
	}