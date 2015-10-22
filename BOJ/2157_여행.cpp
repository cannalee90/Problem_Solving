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

struct edge{
	int there;
	int cost;
	edge();
	edge(int there, int cost) : there(there), cost(cost){}
};

int n, k, m;
vector<vector<edge> > graph;
vector<vector<int > > dp;

int solve(int here, int	cnt) {
	if (here != n && cnt == 0) return -INF;
	int &ret = dp[here][cnt];
	if (ret != -1) return ret;
	if (here == n) return 0;
	ret = -INF;
	for (edge next : graph[here])
		ret = max(ret, solve(next.there, cnt - 1) + next.cost);

	return ret;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> k >> m;
	dp.assign(301 + 1, vector<int>(k + 1, -1));
	graph.assign(n + 1, vector<edge>());
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if (v > u)
			graph[u].push_back(edge(v, w));
	}
	cout << solve(1, k - 1) << endl;
}
