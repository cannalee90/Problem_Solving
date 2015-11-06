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

vector<vector<int> > graph;
vector<int > match;
vector<bool > check;

bool dfs(int here) {
	for (int next : graph[here]){
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	graph.assign(n + 1, vector<int>());
	match.assign(n + 1, -1);
	check.assign(n + 1, false);
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int u = i + 1, v;
			cin >> v;
			graph[u].push_back(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		fill(check.begin(), check.end(), false);
		if (dfs(i))
			ans++;
	}
	cout << n - ans << endl;
}