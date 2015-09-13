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

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int mountain[30][30];
int n, m, t, d;
vector<vector<pair<int, int > >  > graph;


bool isPossible(int h, int w, int t){
	if (h < 0 || w < 0 || h >= n || w >= m) return 0;
	return 1;
}

vector<int> dijkstra(int begin){
	vector<int> ret(n * m, INT_MAX);
	ret[begin] = 0;
	queue<int> que;
	que.push(begin);
	while (!que.empty()){
		int here = que.front();
		que.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int cost = ret[here] + graph[here][i].second;
			
			if (ret[there] > cost){
				ret[there] = cost;
				que.push(there);
			}
		}
	}
	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m >> t >> d;
	graph = vector < vector<pair<int, int > > >(n * m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char c;
			cin >> c;
			if (c >= 'A' && c <= 'Z'){
				c -= 'A';
				mountain[i][j] = (int)c;
			}
			else{
				c -= 'a';
				mountain[i][j] = (int)c + 26;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < 4; k++){
				int next_y = i + mmove[k][0];
				int next_x = j + mmove[k][1];

				int here = (i * m) + j;
				int there = (next_y * m) + next_x;
				if (abs(mountain[i][j] - mountain[next_y][next_x]) > t) continue;
				if (isPossible(next_y, next_x, t)){
					if (mountain[i][j] >= mountain[next_y][next_x]) 
						graph[here].push_back(make_pair(there, 1));
					else
						graph[here].push_back(make_pair(there, (mountain[next_y][next_x] - mountain[i][j]) * (mountain[next_y][next_x] - mountain[i][j])));
					
				}
			}
		}
	}
	int ans = mountain[0][0];
	vector<int> dis = dijkstra(0);
	for (int i = 1; i < n * m; i++){
		vector<int> cost = dijkstra(i);
		if (cost[0] == INT_MAX || dis[i] == INT_MAX) continue;
		if (cost[0] + dis[i] <= d){
			ans = max(mountain[i / m][i % m], ans);
		}
	}
	printf("%d\n", ans );
}