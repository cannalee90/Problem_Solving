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
vector<bool> check;
vector<int> ans;
vector<int> discovery;
int cnt = 0;

int dfs(int here, bool isRoot) {
	discovery[here] = ++cnt;
	int ret = discovery[here];
	int children = 0;
	for (int next : graph[here]) {
		if (discovery[next] == -1) {
			children++;
			int temp = dfs(next, false);
			if (temp >= discovery[here] && !isRoot)
				ans.push_back(here);
			ret = min(ret, discovery[next]);
		}
		else
			ret = min(ret, discovery[next]);
	}
	if ((isRoot && children > 1))
		ans.push_back(here);
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	check.assign(n + 1, false);
	discovery.assign(n + 1, -1);
	graph.assign(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if(discovery[i] == -1)
			dfs(i, true);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	puts("");
}
