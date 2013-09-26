#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include <string.h>
#include <vector>
#include <map>

using namespace std;

#define DT int
#define _for(i, from, to) for(DT i = (from); i < (to); i++)

struct Node {
	char key;
	int count;
	int prefix;
	map<char, Node *> children;
};

Node * init(Node *node) {
	node = new Node;
	node->key = 0;
	node->count = 0;
	node->prefix = 0;

	return node;
}

Node * put(Node *head, string value) {
	DT size = value.length();
	Node *node = head;

	_for(i, 0, size) {
		// cout << value[i];
		node = head->children[value[i]];

		if(!node) {
			Node *buf = NULL;
			node = init(buf);
			node->key = value[i];
		}

		if(size-1 == i) {
			node->count++;
			return node;
		} else {
			node->prefix++;
		}
		
		head->children[value[i]] = node;
		head = node;
	}
}

Node * get(Node *head, string value) {
	DT size = value.length();
	Node *node = head;

	_for(i, 0, size) {
		node = node->children[value[i]];
		cout << value[i] << endl;

		if(!node) {
			return 0;
		}
	}

	return node;
}
// Node () {}

int main() {
	string a, b;
	Node *root = NULL;
	root = init(root);

	cin >> a;
	cin >> b;
	put(root, a);
	Node *result = get(root, b);

	if(result)
		cout << result->key << endl;

	return 0;
}