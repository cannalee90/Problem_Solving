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

#define INF 987654321

struct edge {
	int there;
	int cost;
	int time;
	edge(int there, int cost, int time) : there(there), cost(cost), time(time) {}
};

vector<vector<edge> > graph;
vector<vector<int> > dp;
int n, limit, m;

int solve(int here, int cost) {
	if (cost > limit) return INF;
	int &ret = dp[here][cost];
	if (ret != -1) return ret;
	if (here == n) return 0;
	ret = INF;
	for (edge next : graph[here]){
		ret = min(ret, solve(next.there, cost + next.cost) + next.time);
	}
	return ret;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> limit >> m;
		graph.assign(n + 1, vector<edge>());
		dp.assign(n + 1, vector<int>(limit + 1, -1));
		for (int i = 0; i < m; i++) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back(edge(v, c, d));
		}
		int ans = solve(1, 0);
		if (ans == INF)
			cout << "Poor KCM" << endl;
		else
			cout << ans << endl;
	}
}

