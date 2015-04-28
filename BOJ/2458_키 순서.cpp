#include <iostream>
#include <utility>
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

vector<bool> visited;

int dfs(int here, vector<vector<int> > &graph){
	int ret = 0;
	for (int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if (!visited[there]){
			visited[there] = true;
			ret += dfs(there, graph);
		}
	}
	return ret + 1;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int m;
	int ans = 0;
	vector<vector<int> > graph;
	vector<vector<int> > rgraph;

	cin >> n;
	cin >> m;
	graph = vector<vector<int> >(n + 1);
	rgraph = vector<vector<int> >(n + 1);
	for (int i = 0; i < m; i++){
		int here, there;
		cin >> here >> there;
		graph[here].push_back(there);
		rgraph[there].push_back(here);
	}
	for (int i = 1; i <=n; i++){
		visited = vector<bool>(n + 1);
		visited[i] = true;
		if (dfs(i, graph) + (dfs(i, rgraph) - 1) == n){
			ans++;
		}
	}
	cout << ans << endl;
}
