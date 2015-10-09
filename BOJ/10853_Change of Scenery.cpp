#include <iostream>
#include <utility>
#include <functional>
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

#define INF 987654321

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, p;

	cin >> n >> m >> p;

	vector<int> path;
	vector<vector<pair<int, int > > > graph(n + 1);
	vector<int> dis(n + 1, INF);
	vector<int> cnt(n + 1, 0);

	for (int i = 0; i < p; i++) {
		int num;
		cin >> num;
		path.push_back(num);
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	int begin = path.front();
	int end = path.back();

	cnt[begin] = 1;
	dis[begin] = 0;
	priority_queue<pair<int, int >, vector<pair<int, int > >, greater<pair<int, int > > > pq;
	pq.push(make_pair(0, begin));

	while (!pq.empty()) {
		int here = pq.top().second;
		int c = pq.top().first;

		pq.pop();

		if (dis[here] < c) continue;

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i].first;
			int cost = graph[here][i].second + dis[here];
			if (dis[there] > cost) {

				dis[there] = cost;
				(cnt[here] > 1) ? cnt[there] = 2 : cnt[there] = 1;
				pq.push(make_pair(cost, there));

			}
			else if (dis[there] == cost)
				cnt[there] ++;
		}
	}

	if (cnt[end] > 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}