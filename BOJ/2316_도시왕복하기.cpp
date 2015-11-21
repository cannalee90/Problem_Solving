#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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

#define INF 987654321

struct Maxflow {
	int n;
	struct Edge{
		int next;
		int inv;
		int cap;
	};
	vector<vector<Edge> > graph;
	Maxflow(int n) {
		this->n = n;
		graph.assign(n, vector<Edge>());
	}
	void add_edge(int u, int v, int c, int rev_c) {
		Edge foward, backward;
		foward.next = v;
		foward.cap = c;
		foward.inv = graph[v].size();
		backward.next = u;
		backward.cap = rev_c;
		backward.inv = graph[u].size();
		graph[u].push_back(foward);
		graph[v].push_back(backward);
	}

	int bfs(int source, int sink) {
		vector<bool> visited(n, false);
		vector<pair<int, int > > parent(n, pair<int, int>(-1, -1));
		visited[source] = true;
		queue<int> que;
		que.push(source);
		while (!que.empty()) {
			int here = que.front();
			que.pop();
			for (int i = 0; i < graph[here].size(); i++) {
				int next = graph[here][i].next;
				if (!visited[next] && graph[here][i].cap) {
					visited[next] = true;
					parent[next].first = here;
					parent[next].second = i;
					que.push(next);
				}
			}
		}
		if (parent[sink].first == -1) return 0;

		int minflow = INF;
		
		int p = sink;
		while (parent[p].first != -1) {
			minflow = min(minflow, graph[parent[p].first][parent[p].second].cap);
			p = parent[p].first;
		}
		p = sink;
		while (parent[p].first != -1) {
			Edge& e = graph[parent[p].first][parent[p].second];
			e.cap -= minflow;
			graph[e.next][e.inv].cap += minflow;
			p = parent[p].first;
		}
		return minflow;
	}
	int flow(int source, int sink) {
		int flow = 0;
		int ret = 0;
		while (flow = bfs(source, sink)){
			ret += flow;
		}
		return ret;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	Maxflow mf = Maxflow(n * 2);
	for (int i = 2; i < n; i++) {
		mf.add_edge(i * 2, i * 2 + 1, 1, 0);
	}
	mf.add_edge(0, 1, INF, 0);
	mf.add_edge(2, 3, INF, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		mf.add_edge(u * 2 + 1, v * 2, 1, 0);
		mf.add_edge(v * 2, u * 2 + 1, 1, 0);
	}
	cout << mf.flow(0, 3) << endl;

}

