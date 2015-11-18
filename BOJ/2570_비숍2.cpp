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

bool isRange(int h, int w, int n) {
	if (h < 1 || w < 1 || h > n || w > n) return false;
	return true;
}

bool dfs(vector<vector<int> >& graph, vector<bool>& check, vector<int>& match, int here){
	for (int& next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(graph, check, match, match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}


int main(){
	int n, m;
	int left[110][100] = {};
	int right[110][110] = {};
	
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int h, w;
		cin >> h >> w;
		left[h][w] = -1;
		right[h][w] = -1;
	}
	int lcnt = 0, rcnt = 0;
	for (int i = 1; i <= n; i++) {
		int h = 1, w = i;
		while (isRange(h, w, n)) {
			if (left[h][w] != -1){
				if (h == 1 || left[h - 1][w - 1] == -1)
					left[h][w] = ++lcnt;
				else
					left[h][w] = left[h - 1][w - 1];
			}
			h += 1;
			w += 1;
		}
		h = i; w = 1;
		while (isRange(h, w, n) && left[h][w] < 1) {
			if (left[h][w] != -1){
				if (w == 1 || left[h - 1][w - 1] == -1)
					left[h][w] = ++lcnt;
				else
					left[h][w] = left[h - 1][w - 1];
			}
			h += 1;
			w += 1;
		}
		h = 1, w = n - i + 1;
		while (isRange(h, w, n) && right[h][w] < 1) {
			if (right[h][w] != -1){
				if (h == 1 || right[h - 1][w + 1] == -1)
					right[h][w] = ++rcnt;
				else
					right[h][w] = right[h - 1][w + 1];
			}
			h += 1;
			w -= 1;
		}
		h = i; w = n;
		while (isRange(h, w, n) && right[h][w] < 1) {
			if (right[h][w] != -1){
				if (w == n || right[h - 1][w + 1] == -1)
					right[h][w] = ++rcnt;
				else
					right[h][w] = right[h - 1][w + 1];
			}
			h += 1;
			w -= 1;
		}
	}
	
	rcnt++;
	lcnt++;
	vector<vector<int> > graph(lcnt);
	vector<bool> check(rcnt);
	vector<int> match(rcnt, -1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (left[i][j] == -1) continue;
			int u = left[i][j];
			int v = right[i][j];
			graph[u].push_back(v);
		}
	}
	for (int i = 1; i < lcnt; i++) {
		fill(check.begin(), check.end(), false);
		if (dfs(graph, check, match, i))
			ans++;
	}
	cout << ans << endl;
}
