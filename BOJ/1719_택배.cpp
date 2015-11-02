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

struct Edge{
	int v; 
	int w;
	Edge(){};
	Edge(int v, int w) : v(v), w(w){}
	bool operator > (const Edge &a) const {
		return w < a.w;
	}
};

vector<vector<Edge> > graph;
int n, m;

vector<int> dijkstra(int source) {
	vector<int> dis(n + 1, INF);
	vector<int> parent(n + 1, -1);
	dis[source] = 0;
	priority_queue < Edge, vector<Edge>, greater<Edge> > pq;
	pq.push(Edge(source, 0));
	while (!pq.empty()) {
		int here = pq.top().v;
		int cost = pq.top().w;
		pq.pop();
		if (dis[here] < cost) continue;
		for (Edge next : graph[here]) {
			int next_cost = cost + next.w;
			if (dis[next.v] > next_cost) {
				dis[next.v] = next_cost;
				pq.push(Edge(next.v, next_cost));
				parent[next.v] = here;
			}
		}
	}
	vector<int> ans(n + 1, -1);
	for (int i = 1; i <= n; i++)  {
		int v = i;
		if (source == v || parent[v] == -1) continue;
		
			while (parent[v] != source && ans[v] == -1){
				v = parent[v];
			}
			if (ans[v] == -1)
				ans[i] = v;
			else
				ans[i] = ans[v];
		
	}
	return ans;
}

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	graph = vector<vector<Edge> >(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(Edge(v, w));
		graph[v].push_back(Edge(u, w));

	}
	for (int i = 1; i <= n; i++){
		vector<int> ret = dijkstra(i);
		for (int i = 1; i <= n; i++) {
			if (ret[i] == -1)
				printf("- ");
			else
				printf("%d ", ret[i]);
		}
		puts("");
	}
}

