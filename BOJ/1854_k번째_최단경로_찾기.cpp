#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <string.h>
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

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, int > > > graph(n + 1);
	for (int i = 0; i < m; i++){
		int h, t, w;
		scanf("%d %d %d", &h, &t, &w);
		graph[h].push_back(make_pair(t, w));
	}
	vector<priority_queue<int> > dis(n + 1);
	int cnt = 0;
	priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int > > > pq;
	pq.push(make_pair(0, 1));
	dis[1].push(0);
	while (!pq.empty()){
		cnt ++;
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i].first;
			int weight = graph[here][i].second + cost;
			if (dis[there].size() < k){
				pq.push(make_pair(weight, there));
				dis[there].push(weight);
			}
			else if(dis[there].top() > weight){
				dis[there].push(weight);
				pq.push(make_pair(weight, there));
				dis[there].pop();
			}
		}
	}
	DBL
	for (int i = 1; i <= n; i++){
		if (dis[i].size() != k) cout << "-1" << endl;
		else cout << dis[i].top() << endl;
	}
}