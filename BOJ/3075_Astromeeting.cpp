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
#include<functional>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int p, n, m;
		cin >> p >> n >> m;

		vector<int> begin_point(p);
		vector<vector<pair<int, int > > > graph(n + 1);
		

		for (int i = 0; i < p; i++){
			cin >> begin_point[i];
		}

		for (int i = 0; i < m; i++){
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			graph[t1].push_back(make_pair(t3, t2));
			graph[t2].push_back(make_pair(t3, t1));
		}

		vector<int> total(n + 1, 0);

		for (int i = 0; i < p; i++){
			vector<int> dis(n + 1, 9999999);
			int begin = begin_point[i];
			dis[begin] = 0;
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
			pq.push(make_pair(0, begin));
			while (!pq.empty()){
				int here = pq.top().second;
				int here_dis = pq.top().first;
				pq.pop();
				if (dis[here] > here_dis)
					continue;
				for (int j = 0; j < graph[here].size(); j++){
					int there = graph[here][j].second;
					int there_dis = graph[here][j].first;
					if (here_dis + there_dis < dis[there]){
						dis[there] = here_dis + there_dis;
						pq.push(make_pair(here_dis + there_dis, there));
					}
				}
			}
			for (int j = 1; j <= n; j++){
				total[j] += dis[j]* dis[j];
			}
		}
		int mmin = INT_MAX;
		int min_p = -1;
		for (int i = 1; i <=n; i++){
			if (total[i] < mmin){
				mmin = total[i];
				min_p = i;
			}
		}
		printf("%d %d\n", min_p, mmin);
	}
}