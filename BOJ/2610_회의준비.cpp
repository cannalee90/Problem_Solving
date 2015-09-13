#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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

int n, m;

vector<vector<int > > comp;

void dfs(int vertex, vector<vector<int> > &graph, vector<bool> &visited){
	for (int i = 0; i < graph[vertex].size(); i++){
		int there = graph[vertex][i];
		if (!visited[there]){
			visited[there] = true;
			comp[comp.size() - 1].push_back(there);
			dfs(there, graph, visited);
		}
	}
}

vector<int> bfs(int begin, vector<vector<int > > &graph){
	vector<int> dis(n + 1, INT_MAX);
	queue<pair<int, int > > que;
	que.push(make_pair(begin, 0));
	dis[begin] = 0;
	while (!que.empty()){
		int here = que.front().first;
		int cost = que.front().second;
		que.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i];
			if (dis[there] > cost + 1){
				dis[there] = cost + 1;
				que.push(make_pair(there, cost + 1));
			}
		}
	}
	return dis;
}
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >>  m;
	vector<vector<int> > graph(n + 1);
	vector<bool> visited(n + 1, false);
	for (int i = 0; i < m; i++){
		int h, t;
		cin >> h >> t;
		graph[h].push_back(t);
		graph[t].push_back(h);
	}
	int num_com = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			visited[i] = true;
			comp.push_back(vector<int>());
			comp[comp.size() - 1].push_back(i);

			dfs(i, graph, visited);
		
		}
	}
	vector<int> ans;
	for (int i = 0; i < comp.size(); i++){
		int mmin = INT_MAX;
		int mminp;
		for (int j = 0; j < comp[i].size(); j++){
			vector<int> dis = bfs(comp[i][j], graph);
			int mmax = INT_MIN;
			for (int k = 1; k <= n; k++){
				if (dis[k] != INT_MAX){
					mmax = max(mmax, dis[k]);
				}
			}
			if (mmin > mmax){
				mmin = mmax;
				mminp = comp[i][j];
			}
		}
		ans.push_back(mminp);
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}