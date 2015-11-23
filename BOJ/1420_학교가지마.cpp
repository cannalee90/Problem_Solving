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

int n, m;
int mmove[4][2] = { {1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 }};

bool isPossible(int h, int w) {
	if (h < 0 || w < 0 || h >= n || w >= m) return false;
	return true;
}

int coorToVertex(int h, int w) {
	return (h * m) + w;
}

int main(){
	scanf("%d %d", &n, &m);
	Maxflow mf = Maxflow((n * m) + (n * m));
	int out = n * m;
	int source, sink;
	char board[110][110] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'K') {
				source = coorToVertex(i, j);
			} else if (board[i][j] == 'H'){
				sink = coorToVertex(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') continue;
			mf.add_edge(coorToVertex(i, j), coorToVertex(i, j) + out, 1, 0);
			for (int k = 0; k < 4; k++){
				
				int nextH = i + mmove[k][0];
				int nextW = j + mmove[k][1];
				if (isPossible(nextH, nextW) && board[nextH][nextW] != '#') {
					mf.add_edge(coorToVertex(i, j) + out, coorToVertex(nextH, nextW), INF, 0);
				}
			}
		}
	}
	ll flow = mf.flow(source + out, sink);
	if (flow > 90000000)
		cout << "-1" << endl;
	else
		cout << flow << endl;
}

