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
vector<vector<int>  >  graph;


void delete_edge(vector<vector<int> >  &parent, int there){
	for (int i = 0; i < parent[there].size(); i++){
		int here = parent[there][i];
		graph[here][there] = 0;
		delete_edge(parent, here);
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while (cin >> n >> m){
		int begin, end;
		if (n == 0 && m == 0)
			break;
		cin >> begin >> end;
		graph.clear();
		graph.resize(n + 1, vector<int>(n + 1, 0));
		vector<int> dis(n + 1, INT_MAX);
		vector<vector<int > > parent(n + 1);
		for (int i = 0; i < m; i++){
			int t, h, w;
			cin >> t >> h >> w;
			graph[t][h] = w;
		}
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push(make_pair(0, begin));
		dis[begin] = 0;
		while (!pq.empty()){
			int here = pq.top().second;
			int here_dis = pq.top().first;
			pq.pop();
			for (int i = 0; i <n; i++){
				if (graph[here][i] != 0){
					int there = i;

					int cost = here_dis + graph[here][there];

					if (dis[there] > cost){
						parent[there].clear();
						parent[there].push_back(here);
						dis[there] = cost;
						pq.push(make_pair(cost, there));
					}
					else if (dis[there] == cost){
						parent[there].push_back(here);
					}
				}	
			}
		}
		delete_edge(parent, end);
		pq.push(make_pair(0, begin));
		parent.clear();
		dis.clear();
		dis.resize(n + 1, INT_MAX);
		parent.resize(n + 1);
		dis[begin] = 0;
		while (!pq.empty()){
			int here = pq.top().second;
			int here_dis = pq.top().first;
			pq.pop();
			for (int i = 0; i < n; i++){
				if (graph[here][i] != 0){
					int there = i;
					int cost = here_dis + graph[here][i];
					if (dis[there] > cost){
						parent[there].clear();
						parent[there].push_back(here);
						dis[there] = cost;
						pq.push(make_pair(cost, there));
					}
					else if (dis[there] == cost){
						parent[there].push_back(here);
					}
				}
			}
		}
		if (dis[end] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << dis[end] << endl;
	}
}