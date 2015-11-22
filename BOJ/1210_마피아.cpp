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
	int source, sink;
	
	cin >> n >> m;
	cin >> source >> sink;
	Maxflow mf = Maxflow(n * 2);
	vector<int> cap(n);

	//vertex capacity가 주어진 비용
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		cap[i] = c;
		mf.add_edge(i * 2, i * 2 + 1, c, 0);
	}
	source--;
	sink--;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		mf.add_edge(u * 2 + 1, v * 2, INF, 0); //in과 out으로 나누기 
		mf.add_edge(v * 2 + 1, u * 2, INF, 0); 
	}

	int a = mf.flow(source * 2, sink * 2 + 1); //in(s)와 out(t)로 max-flow
	vector<bool> check(n * 2);
	queue<int> que;
	que.push(source * 2);
	check[source * 2] = true;
	int tmp  = 0;

	//min-cut의 역추적하기.
	//in(s)에서부터 bfs를 돌아버린다. 그리고 방문한 정점을 check에 기록해둔다, 이때 residual이 0인 정점은 제외
	//그리고 in(vi)가 1이고 out(vi) = 0인 정점을 모두 출력한다.
	//이는 min-cut therom의 정의를 생각해보면 자명하다.
	//만약 in(vi) == 1 and out == 1인 정점은 현재 정점이랑 상관없이 flow는 계속 흐르는거고.
	//in(vi) == 1 and out(vi) == 0인 정점때문에 flow가 현재 흐르지 않는 상태.
	while (!que.empty()) {
		int here = que.front();
		que.pop();
		for (int i = 0; i < mf.graph[here].size(); i++) {
			int next = mf.graph[here][i].next;
			if(!check[next] && mf.graph[here][i].cap){	
				check[next] = true;
				que.push(next);
			}
		}
	}
	for (int i = 0; i < n * 2; i+=2) {
		if (check[i] && !check[i + 1])
			cout << (i / 2) + 1 << " ";
	}
	cout << endl;
}

