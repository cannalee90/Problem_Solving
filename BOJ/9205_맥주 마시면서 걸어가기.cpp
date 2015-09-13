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

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		n += 2;
		vector<vector<pair<int, int > > > graph(n);
		vector<pair<int, int > > vp(n);
		for (int i = 0; i < n; i++) scanf("%d %d", &vp[i].first, &vp[i].second);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				int dis = abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second);
				if (dis <= 1000) {
					graph[i].push_back(make_pair(j, dis));
				}
			}
		}
		queue<int> que;
		que.push(0);
		vector<int> dis(n, INT_MAX);
		dis[0] = 0;
		while (!que.empty()){
			int here = que.front();
			que.pop();
			for (int i = 0; i < graph[here].size(); i++){
				int there = graph[here][i].first;
				int cost = dis[here] + graph[here][i].second;
				if (dis[there] > cost){
					dis[there] = cost;
					que.push(there);
				}
			}
		}
		if (dis[n - 1] != INT_MAX) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
}