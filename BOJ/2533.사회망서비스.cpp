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

vector<vector<int > > graph;
vector<vector<int> > dp;
vector<bool> check;

void solve(int here) {
	int &zero = dp[here][0];
	int &one = dp[here][1];
	one++;
	check[here] = true;
	for (int next : graph[here]) {
		if (!check[next]) {
			solve(next);
			zero += dp[next][1];
			one += min(dp[next][0], dp[next][1]);
		}
	}
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	graph.assign(n + 1, vector<int>());
	dp.assign(n + 1, vector<int>(2, 0));
	check.assign(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &v, &u);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	solve(1); //DP[i][0] 내가 얼리어뎁터가 아닐때, DP[i][1] 내가 얼리어뎁터일때의 최소값.
	cout << min(dp[1][0], dp[1][1]) << endl;
}

