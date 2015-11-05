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

int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int > > > graph(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}
	priority_queue<pair<int, int >, vector<pair<int, int > >, greater<pair<int, int > > > pq;
	vector<pair<int, int > > dis(n + 1, pair<int, int>(INF, INF));
	vector<int> parent(n + 1, -1);
	pq.push(make_pair(0, 1));

	dis[1].first = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (dis[here].first != cost && dis[here].second != cost) continue;
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int next_cost = graph[here][i].second + cost;
			if (dis[next].first > next_cost) {
				pq.push(make_pair(next_cost, next));
				dis[next].second = min(dis[next].second, dis[next].first);
				dis[next].first = next_cost;
				parent[next] = here;

			}
			else if (dis[next].second > next_cost && dis[next].first < next_cost) {
				pq.push(make_pair(next_cost, next));
				dis[next].second = next_cost;
			}
		}
	}
	cout << dis[n].second << endl;
}