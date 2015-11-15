#include <iostream>
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

#define INF 987654321

pair<ll, ll> dfs(vector<vector<pair<ll, ll > > >& graph, vector<bool>& visited, int here) { 
	visited[here] = true;
	pair<ll, ll > ret(here, 0);
	for (pair<ll, ll >& next : graph[here]) {
		if (!visited[next.first]){
			auto tmp = dfs(graph, visited, next.first);
			tmp.second += next.second;
			if (tmp.second > ret.second){
				swap(tmp, ret);
			}
		}
	}
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n;
	vector<vector<pair<ll, ll > > > graph(n + 1);
	while (cin >> m){
		ll u, v, w;
		while (true){
			cin >> v;
			if (v == -1) break;
			else cin >> w;
			graph[m].push_back(make_pair(v, w));
		}
	}
	vector<bool> visited(n + 1, false);
	auto t = dfs(graph, visited, n); //아무거나 찍고 가장 먼점을 찾는다
	fill(visited.begin(), visited.end(), false); //그리고 그 먼점으로 부터 다시 가장 먼점을 찾는다.
	auto u = dfs(graph, visited, t.first); //그 거리가 트리의 지름
	cout << u.second << endl;
}
