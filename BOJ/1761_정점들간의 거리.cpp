#include <iostream>
#include <utility>
#include <functional>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

#define INF 987654321

vector<vector<pair<int, int > > > tree;
vector<vector<pair<int, int > > > graph;
vector<bool> visited;
vector<int> h;

void make_tree(int here, int height) {
	visited[here] = true;
	h[here] = height;
	for (int i = 0; i < tree[here].size(); i++) {
		int there = tree[here][i].first;
		int weight = tree[here][i].second;
		if (!visited[there]) {
			graph[there].push_back(make_pair(here, weight));
			make_tree(there, height + 1);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	tree.assign(n + 1, vector<pair<int, int > >());
	graph.assign(n + 1, vector<pair<int, int > >());
	h.assign(n + 1, 0);
	visited.assign(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		tree[u].push_back(make_pair(v, w));
		tree[v].push_back(make_pair(u, w));
	}
	make_tree(1, 0);
	graph[1].push_back(make_pair(1, 0));

	for (int i = 0; i < m; i++) {
		int u, v;
		int u_dis = 0, v_dis = 0;
		scanf("%d %d", &u, &v);
		if (h[v] < h[u])
			swap(u, v);
		while (h[v] != 0 && h[v] != h[u]) {
			v_dis += graph[v][0].second;
			v = graph[v][0].first;
		}
		while (u != v && h[u] != 0) {
			v_dis += graph[v][0].second;
			v = graph[v][0].first;
			u_dis += graph[u][0].second;
			u = graph[u][0].first;
		}
		printf("%d\n", v_dis +  u_dis);
	}
}
