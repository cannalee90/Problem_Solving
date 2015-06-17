#include <iostream>
#include <climits>
#include <functional>
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

int m, t, n, k;
vector<vector<int > > graph;
vector<vector<int > > hyper;
vector<int>  dis;

int dijkstra(){
	dis = vector<int>(n + 1, INT_MAX);
	dis[1] = 0;
	queue<int> que;
	que.push(1);
	vector<bool> visited(m, false);
	while(!que.empty()){
		int here = que.front();
		int here_cost = dis[here];
		que.pop();
		if(dis[here] < here_cost) continue;
		for (int i = 0; i < graph[here].size(); i++){
			if (visited[graph[here][i]]) continue;
			visited[graph[here][i]] = true;
			for (int j = 0; j < hyper[graph[here][i]].size(); j++){
				int there = hyper[graph[here][i]][j];
				int cost = here_cost + 1;
				if (dis[there] > cost){
					dis[there] = cost;
					que.push(there);
					if (there == n)
						return dis[there];
				}
			}
		}
	}
	return dis[n];
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> k >> m;
	graph = vector < vector<int > >(n + 1);
	hyper = vector < vector<int > >(m + 1);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < k; j++){
			scanf("%d", &t);
			hyper[i].push_back(t);
			graph[t].push_back(i);
		}
	}
	int ans = dijkstra();
	if (ans == INT_MAX)
		cout << "-1" << endl;
	else
		cout << ans + 1 << endl;
}

