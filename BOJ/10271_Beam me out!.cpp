#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

vector<int> visited;
bool isCycle;

void check_cycle(vector<vector<int> > &graph, int here) {
	visited[here] = 1;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (visited[there] == 0) {
			check_cycle(graph, there);
			visited[there] = -1;
		}
		else if (visited[there] == 1)
			isCycle = true;
	}
}

void dfs(vector<vector<int> > &graph, vector<bool> &discovery, int here) {
	discovery[here] = true;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (!discovery[there])
			dfs(graph, discovery, there);
	}
}


int main() {
	vector<vector<int> > graph, rgraph;
	vector<bool> discovery, rdiscovery;
	bool isPardon = true;
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	graph = vector<vector<int> >(n + 1);
	rgraph = vector<vector<int> >(n + 1);
	visited = vector<int>(n + 1);
	discovery = vector<bool>(n + 1);
	rdiscovery = vector<bool>(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int m, t;
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> t;
			graph[i + 1].push_back(t);
			rgraph[t].push_back(i + 1);
		}
	}
	check_cycle(graph, 1);
	dfs(graph, discovery, 1);
	dfs(rgraph, rdiscovery, n);
	
	for(int i = 1; i <= n; i ++) {
		if (discovery[i] == true && rdiscovery[i] == false)
			isPardon = false;
	}
	if (isPardon)
		cout << "PARDON ";
	else
		cout << "PRISON ";
	if (isCycle)
		cout << "UNLIMITED" << endl;
	else
		cout << "LIMITED" << endl;

}