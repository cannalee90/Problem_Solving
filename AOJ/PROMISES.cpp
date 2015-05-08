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
#include <functional>

typedef long long ll;
using namespace std;

vector<vector<pair<int, int > > > graph;
vector<int> here;
vector<int> temp;
vector<int> dis;

int n, m1, m2;


vector<int > dijkstra(int begin){
	dis = vector<int>(n, INT_MAX);
	dis[begin] = 0;
	priority_queue < pair<int, int >, vector<pair<int, int>  >, greater<pair<int, int > > > pq;
	pq.push(make_pair(0, begin));
	while (!pq.empty()){
		int here = pq.top().second;
		int here_cost = pq.top().first;
		pq.pop();
		if (dis[here] < here_cost) continue;
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].second;
			int cost = here_cost + graph[here][i].first;
			if (dis[there] > cost){
				dis[there] = cost;
				pq.push(make_pair(cost, there));
			}
		}
	}
	return dis;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	scanf("%d", &t);
	while(t--){
		int ans = 0;
		scanf("%d%d%d", &n, &m1, &m2);
		vector<vector<int > > matrix_graph(n, vector<int>(n, INT_MAX));
		graph = vector<vector<pair<int, int > > >(n);
		here.clear();
		for (int i = 0; i < m1; i++){
			int h, t, w;
			scanf("%d %d %d", &h, &t, &w);
			graph[h].push_back(make_pair(w, t));
			graph[t].push_back(make_pair(w, h));
		}
		for (int i = 0; i < m2; i++){
			int h, t, w;
			scanf("%d %d %d", &h, &t, &w);
			here = dijkstra(h);
			graph[h].push_back(make_pair(w, t));
			graph[t].push_back(make_pair(w, h));
			temp = dijkstra(h);
			if (here == temp)
				ans++;
		}
		cout << ans << endl;
	}
}