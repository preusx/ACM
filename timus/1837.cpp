#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define root "Isenbaev"

struct mapComparator {
    bool operator()(const std::string& a, const std::string& b) const {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    }
};

map<string, pair<int, set<string> >, mapComparator> graph;
set<string> blank;

void trace(string name, int count) {
	if(graph.find(name) != graph.end()) {
		for(set<string>::iterator i = graph[name].second.begin();\
			i != graph[name].second.end(); i++) {
			if(graph[*i].first == -1 || graph[*i].first > count) {
				graph[*i].first = count;
			}
		}

		for(set<string>::iterator i = graph[name].second.begin();\
			i != graph[name].second.end(); i++) {
			if(graph[*i].first == count) {
				trace(*i, count+1);
			}
		}
	}
}

int main() {
	int n;
	string one, two, three;

	// map<string, int> indexes;
	// vector<string> names;
	// vector< vector<int> > graph;
	// vector<int> blank;

	// indexes[root] = 0;
	// names[0] = root;
	// graph.push_back(blank);

	// graph[root] = make_pair(0, blank);

	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		cin >> one >> two >> three;

		if(graph.find(one) == graph.end()) {
			graph[one] = make_pair(-1, blank);
		}

		if(graph.find(two) == graph.end()) {
			graph[two] = make_pair(-1, blank);
		}

		if(graph.find(three) == graph.end()) {
			graph[three] = make_pair(-1, blank);
		}

		
		graph[one].second.insert(two);
		graph[one].second.insert(three);

		graph[two].second.insert(one);
		graph[two].second.insert(three);

		graph[three].second.insert(two);
		graph[three].second.insert(one);
	}

	trace(root, 1);
	if(graph.find(root) != graph.end()) {
		graph[root].first = 0;
	}

	for(map< string, pair<int, set<string> > >::iterator i = graph.begin();\
		i != graph.end(); i++) {

		cout << i->first << ' ';

		if(i->second.first >= 0) {
			cout << i->second.first;
		} else {
			cout << "undefined";
		}

		cout << endl;
	}

	return 0;
}