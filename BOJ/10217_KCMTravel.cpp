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

class edge{
public:
	int v;
	int w;
	int c;
	edge(int a, int b, int c) : v(a), w(b), c(c){}
	edge(){}
	bool operator>(const edge &a)const {
		return w > a.w;
	}
};

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k, m;
		scanf("%d %d %d", &n, &k, &m);
		vector<vector<edge> > graph(n + 1);
		for (int i = 0; i < m; i++){
			int h, t, c, w;
			scanf("%d %d %d %d",&h, &t, &c, &w);
			graph[h].push_back(edge(t, w, c));
		}
		vector<pair<int, int > > dis(n + 1, pair<int, int >(INT_MAX, INT_MIN)); //first는 거리 second는 비용		
		priority_queue<edge, vector<edge>, greater<edge> > pq;
		dis[1] = pair<int, int>(0, k);
		pq.push(edge(1, 0, 0));
		edge here;
		while (!pq.empty()){
			here = pq.top();
			pq.pop();
			for (int i = 0; i < graph[here.v].size(); i++){
				int there = graph[here.v][i].v;
				int weight = here.w + graph[here.v][i].w;
				int cost = graph[here.v][i].c + here.c;
				if (cost > k) continue;
				if (dis[there].first > weight || dis[there].second < cost){
					if (dis[there].first > weight) dis[there].first = weight;
					if (dis[there].second < cost) dis[there].second = cost;
					pq.push(edge(there, weight, cost));
				}
			}
		}
		if (dis[n].first == INT_MAX) 
			cout << "Poor KCM" << endl;
		else 
			cout << dis[n].first << endl;
	}
}