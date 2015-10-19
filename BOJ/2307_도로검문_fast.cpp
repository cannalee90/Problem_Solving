#include <iostream>
#include <climits>
#include <functional>
#include <utility>
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

vector < vector<pair<int, int > > > graph;
vector < vector<bool > > check;
vector<int> parent;
int n, m;

int dijkstra(int u, int v) {
	priority_queue<pair<int, int >, vector<pair<int, int > >, greater<pair<int, int > > > pq;
	pq.push(make_pair(0, 1));
	vector<int> dis(n + 1, 987654321);
	dis[1] = 0;
	while (!pq.empty()) {
		auto here = pq.top().second;
		auto cost = pq.top().first;
		pq.pop();
		if (dis[here] < cost) 
			continue;
		
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int nextdis = graph[here][i].second + cost;	
			if ((here == u && next == v) || (here == v && next == u))
				continue;
			if (dis[next] > nextdis) {
				pq.push(make_pair(nextdis, next));
				dis[next] = nextdis;
				parent[next] = here;
			}
		}
	}
	return dis[n];
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int > >());
	check.assign(n + 1, vector<bool>());
	parent.assign(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >>w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	int mmin = dijkstra(0, 0);
	int ans = -987654321;
	int vertex = n;
	while(parent[vertex] != -1) {
		int u = vertex;
		int v = parent[vertex];
		ans = max(ans, dijkstra(u, v));		
		vertex = v;
	}
	if (ans == 987654321)
		cout << "-1" << endl;
	else
		cout << ans - mmin << endl;
}