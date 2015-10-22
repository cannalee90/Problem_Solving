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
vector<vector<int> > graph;
vector<bool> check;
vector<int> match;

bool dfs(int here) {
	for (int next : graph[here]) {
		if (!check[next]) {
			check[next] = true;
			if (match[next] == -1 || dfs(match[next])){
				match[next] = here;
				return true;
			}
		}
	}
	return false;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	graph.assign(n + 1, vector<int>());
	check.assign(n + 1, false);
	match.assign(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(check.begin(), check.end(), false);
		if (dfs(i))
			ans++;
	}
	cout << ans << endl;
}
