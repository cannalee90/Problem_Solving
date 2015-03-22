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

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	vector<pair<long, long > > ver_list;
	map<ll, ll> vertex;
	vector<vector<long long> > graph(n);
	for (int i = 0; i < n; i++){
		string v;
		cin >> v;
		ll ver_num = 0;
		ll binary = 1;
		for (int i = v.size() - 1; i >= 0; i--){
			if (v[i] == '1'){
				ver_num += binary;
			}
			binary *= 2;
		}
		ver_list.push_back(make_pair(ver_num, i));
		vertex[ver_num] = i;
	}

	for (int i = 0; i < n; i++){
		ll temp = 1;
		ll here = ver_list[i].first;
		for (int j = 0; j < m; j++){
			long long num;
			if (here & temp){
				num = here ^ temp;
				if (vertex.count(num)){
					int there = vertex[num];
					graph[ver_list[i].second].push_back(there);
					graph[there].push_back(ver_list[i].second);
				}

			}
			temp *= 2;
		}
	}

	vector<int> dis(n, INT_MAX);
	vector<int> track(n, -1);

	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > > pq;
	pq.push(make_pair(0, 0));
	dis[0] = 0;

	vector<int> res;
	while (!pq.empty()){
		int here = pq.top().second;
		int here_dis = pq.top().first;
		pq.pop();
		if (dis[here] < here_dis)
			continue;
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i];
			if (dis[there] > here_dis + 1){
				dis[there] = here_dis + 1;
				pq.push(make_pair(here_dis + 1, there));
				track[there] = here;
			}
		}
	}

	int q , begin, end;
	cin >> q;
	for (int i = 0; i < q; i++){
		begin = 0;
		scanf("%d", &end);
		end -= 1;
		
		if (dis[end] == INT_MAX){
			printf("-1\n");
			continue;
		}
		res.clear();
		while (track[end] != -1){
			res.push_back(end);
			end = track[end];
		}
		res.push_back(begin);
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++){
			printf("%d ", res[i] + 1);
		}
		cout << endl;
	}
}