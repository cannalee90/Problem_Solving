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

int vcnt;
int sccidx;
vector<bool> check;
vector<bool> last;

int SCC(vector<vector<int> > &graph, vector<int> &discovery, vector<int> &scc, stack<int> &st, int here) {
	//Get SCC
	discovery[here] = ++vcnt;
	int ret = discovery[here];
	st.push(here);
	
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (discovery[there] == INF)
			ret = min(ret, SCC(graph, discovery, scc, st, there));
		else if (scc[there] == -1) 
			ret = min(ret, discovery[there]);
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

ll sol(vector<vector<int> > &graph, vector<ll> &sccmoney, vector<ll> &dp, int here) {
	//DAG Memoization
	ll &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		ll mmin =max(ret, sol( graph, sccmoney, dp, there));
		if (check[there]) {
			ret = max(ret, mmin);
			check[here] = true;
		}
	}
	if (check[here]){
		ret += sccmoney[here];
		return ret;
	} else
		return 0;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, k;
	int begin;
	int s, p;
	cin >> n >> m;

	vector<vector<int> > graph(n + 1);
	vector<int> money(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		cin >> money[i];

	cin >> s >> p;
	vector<int> end(p);

	vector<int> discovery(n + 1, INF);
	vector<int> scc(n + 1, -1);
	stack<int> st;

	for (int i = 1; i <= n; i++) {
		if (discovery[i] == INF)
			SCC(graph, discovery, scc, st, i);
	}
	vector<vector<int > > sccgraph(sccidx);
	vector<ll> sccmoney(sccidx);

	for (int i = 1; i <= n; i++) {
		int u = scc[i];
		sccmoney[u] += money[i];
		for (int j = 0; j < graph[i].size(); j++) {
			int v = scc[graph[i][j]];
			if(u != v) 
				sccgraph[v].push_back(u);
		}
	}
	//SCC Endpoint Graph 시작 포인트를 마지막점으로 하고 레스토랑을 시작점으로 그래프를 만드는게 좀 더 쉽다.
	//역으로 만들어서 돌려버리면 된다.

	vector<int> start;
	for (int i = 0; i < p; i++) {
		int u;
		cin >> u;
		start.push_back(scc[u]);
		//Get Endpoint
	}

	for (int i = 0; i < sccidx; i++) {
		sort(sccgraph[i].begin(), sccgraph[i].end());
		sccgraph[i].erase(unique(sccgraph[i].begin(), sccgraph[i].end()), sccgraph[i].end());
	}
	//그래프 정리 

	ll ans = LLONG_MIN;
	//재귀dp를 돌리는데. 만약 1을 못찍었으면 이건 답이 없다고.. 돌려주면됨
	//dag이기 때문에 굉장히 쉽게 돌리면됨
	for (int i = 0; i < p; i++) {
		vector<ll> dp(sccidx, -1);
		check = vector<bool>(sccidx, false);
		check[scc[s]] = true;
		sol(sccgraph, sccmoney, dp, start[i]);

	
		if(dp[scc[s]] != -1)
			ans = max(dp[start[i]], ans);
	}
	cout << ans << endl;
}