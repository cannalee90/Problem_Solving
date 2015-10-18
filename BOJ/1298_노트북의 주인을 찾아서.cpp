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

vector <int> b;
vector<bool> check;
vector <vector<int> > graph;

bool dfs(int here) {
	for (int next : graph[here]) {
		if (check[next]) 
			continue;
		check[next] = true;
		if(b[next] == -1 || dfs(b[next])){
			b[next] = here;
			return true;
		}
	}
	return false;
}


int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;

	b.assign(m + 1, -1);
	check.assign(m + 1, false);
	graph.assign(n + 1, vector<int>());
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
