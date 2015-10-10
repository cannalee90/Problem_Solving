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

int sccidx;
int vidx;

int SCC(vector<vector<int> > &graph, vector<int> &discovery, stack<int> &st, vector<int> &scc, int here) {
	discovery[here] = ++vidx;
	int ret = discovery[here];
	st.push(here);

	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (discovery[there] == INF)
			ret = min(ret, SCC(graph, discovery, st, scc, there));
		else if (scc[there] == -1)
			ret = min(discovery[there], ret);
	}
	if (ret == discovery[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			scc[t] = sccidx;
			if (t == here)
				break;
		}
		sccidx++;
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<int> > graph(n + 1);
		vector<int> discovery(n + 1, 987654321);
		stack<int> st;
		vector<int> scc(n + 1, -1);
		vector<vector<bool> > sccgraph;

		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}

		sccidx = 0;
		vidx = 0;

		for (int i = 1; i <= n; i++) {
			if (discovery[i] == 987654321)
				SCC(graph, discovery, st, scc, i);
		}
		sccgraph = vector<vector<bool> >(sccidx, vector<bool>(sccidx, false));
		vector<int> indegree(sccidx, 0);
		vector<int> outdegree(sccidx, 0);

		int zin = 0;
		int zout = 0;

		//coner case..이미 모두 한개의 SCC일때. 이거 몰라서 개삽질함.
		
		if (sccidx == 1) {
			puts("0");
			continue;
		}

		//그래프를 SCC로 나눈다음 SCC끼리 연결하면 전체 그래프가 압축된 DAG그래프가 나오게 된다.(컴포넌트가 하나라는 보장은 없음)
		//이렇게 나온 압축된 그래프를 한개의 SCC로 만들어야 할때 더해야할 최소한에 엣지를 구하는 문제이다.
		//최소한의 엣지를 구하는 방식은. max(# of indegree가 0인 정점,  # of outdegree가 0인 정점) 이다.

		for (int i = 1; i <= n; i++) {
			int here = i;
			for (int j = 0; j < graph[here].size(); j++){
				int there = graph[here][j];
				if (scc[there] != scc[here]) {
					outdegree[scc[here]]++;
					indegree[scc[there]]++;
				}
			}
		}

		for (int i = 0; i < sccidx; i++) {
			if (indegree[i] == 0) zin++;
			if (outdegree[i] == 0) zout++;
		}

		cout << max(zin, zout) << endl;
	}
}