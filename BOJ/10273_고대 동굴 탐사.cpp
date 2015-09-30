#include <iostream>
#include <fstream>
#include <string>
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

vector<int> vertex, dp;
vector<int> parent, ans;
vector<vector<pair<int, int > > > graph;


int tsort(int here) {
	int &ret = dp[here];
	if (ret != 0) return ret;
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i].first;
		int w = graph[here][i].second;
		int temp = tsort(there) - w;
		if (temp > ret) {
			ret = temp;
			parent[here] = there;
		}
	}
	ret += vertex[here];
	return ret;
}

void track(int here) {
	ans.push_back(here);
	if (parent[here] == -1) return;
	else{
		track(parent[here]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vertex = vector<int>(n + 1);
		dp = vector<int>(n + 1);
		parent = vector<int>(n + 1, -1);
		graph = vector<vector<pair<int, int > > >(n + 1);

		for (int i = 1; i <= n; i++)
			scanf("%d", &vertex[i]);
		for (int i = 0; i < m; i++) {
			int h, t, w;
			scanf("%d %d %d", &h, &t, &w);
			graph[h].push_back(make_pair(t, w));
		}

		int temp = tsort(1);
		ans = vector < int >();
		track(1);
		cout << temp << " " << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}