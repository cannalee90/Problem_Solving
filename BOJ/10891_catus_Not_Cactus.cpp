#include <iostream>
#include <climits>
#include <functional>
#include <utility>
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

vector<vector<int > > graph;
vector<int> discovery;
vector<int> check;
int cnt;

int dfs(int here, int parent) {
	discovery[here] = ++cnt;
	check[here] = 1;
	int mmin = discovery[here];
	int tmp = 0;
	for (int next : graph[here]) {
		if (next == parent) continue;
		if (check[next] == 0) {
			int a = dfs(next, here);
			check[next] = -1;
			mmin = min(a, mmin);
			if (discovery[here] >= a) //만약 나까지 오는 backedge가 있으면 카운트를 증가.
				tmp++;
		}
		else if (discovery[here] > discovery[next] && check[next] == -1) { //cross edge일 경우에는 무저건 아니다.
			cout << "Not cactus" << endl;
			exit(0);
		}
		else if (discovery[next] < discovery[here] && check[next] == 1) { //back edge일 경우에는 카운트를 증가한다
			mmin = discovery[next];
			tmp++;
		}
	}
	if (tmp > 1) { //카운트가 2 이상이면 
		cout << "Not cactus" << endl;
		exit(0);
	}
	return mmin;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	graph.assign(n + 1, vector<int>());
	discovery.assign(n + 1, -1);
	check.assign(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	cout << "Cactus" << endl;
}

