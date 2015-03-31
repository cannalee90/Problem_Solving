#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>

#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;
int n, m;
vector<bool> visited;
ll ans = 1;
vector<vector<int> > graph;


void dfs(int here){
	for (int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if (!visited[there]){
			ans *= 2;
			visited[there] = true;
			dfs(there);
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	visited.resize(n + 1, false);
	graph.resize(n + 1);
	for (int i = 0; i < m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			visited[i] = true;
			dfs(i);
		}
	}
	cout << ans << endl;
}