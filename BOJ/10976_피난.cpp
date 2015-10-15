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
vector<vector<int> > graph;
vector<int> dis;
vector<int> parent;

int main(){
	freopen("input.txt", "r", stdin);
	int t; 
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > capacity(n + 1, vector<int>(n + 1, 0));
		vector<vector<int> > flow(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			if (u == 1 || v == n)
				capacity[u][v] = 1;
			else
				capacity[u][v] = n;
		}
		int ans = 0;
		while (true) {
			parent.assign(n + 1, -1);
			dis.assign(n + 1, INF);
			dis[1] = 0;
			queue<int> que;
			que.push(1);
			while (!que.empty() && parent[n] == -1) {
				int here = que.front();
				que.pop();
				for (int i = 1; i <= n; i++) {
					int there = i;
					if (capacity[here][there] > 0 && parent[there] == -1) {
						que.push(there);
						parent[there] = here;
					}
				}
			}
			if (parent[n] == -1)
				break;
			int u = n;
			while(u != 1){
				int here = parent[u];
				int there = u;
				capacity[here][there]--;
				capacity[there][here]++;
				u = parent[u];
			}
			ans++;
		}
		cout << ans << endl;
	}
}
