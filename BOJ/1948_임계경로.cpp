#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

long long ans;
vector<vector<bool> > edges;
vector<bool>  visited;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > graph(n + 1);
	vector<vector<pair<int, int> > > track(n + 1);
	edges.resize(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; i++){
		int h, t, w;
		scanf("%d %d %d", &h, &t, &w);
		graph[h].push_back(make_pair(t, w));
		track[t].push_back(make_pair(h, w));
	}
	int begin, end;
	cin >> begin >> end;
	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
	pq.push(make_pair(0, begin));
	vector<int> dis(n + 1, INT_MIN);
	vector<vector<int > > parent(n + 1);

	dis[begin] = 0;

	while (!pq.empty()){
		int here = pq.top().second;
		int here_dis = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int cost = here_dis + graph[here][i].second;
			if (dis[there] < cost){
				dis[there] = cost;
				parent[there].clear();
				parent[there].push_back(here);
				pq.push(make_pair(cost, there));
			}
			else if (dis[there] == cost)
				parent[there].push_back(here);
		}
	}
	visited.resize(n + 1, false);
	long long ans = 0;
	cout << dis[end] << endl;
	visited[end] = true;
	queue <int> v;
	v.push(end);
	while (!v.empty()){
		int here = v.front();
		v.pop();
		if (here == begin)
			continue;
		for (int i = 0; i < parent[here].size(); i++){
			int there = parent[here][i];
			ans++;
			if (!visited[there]){
				visited[there] = true;
				v.push(there);
			}
		}
	}
	cout << ans << endl;
}