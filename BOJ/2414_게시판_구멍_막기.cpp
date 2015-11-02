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

char board[100][100];
int r[100][100];
int h[100][100];
vector<vector<int> > graph;
vector<bool> check;
vector<int> match;

bool dfs(int here) {
	for (int next : graph[here])  {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	memset(r, -1, sizeof(r));
	memset(h, -1, sizeof(h));
	int rcnt = 0, hcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.') continue;
			if (j == 0 || r[i][j - 1] == -1)
				r[i][j] = rcnt++;
			else
				r[i][j] = r[i][j - 1];
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] == '.') continue;
			if (i == 0 || h[i - 1][j] == -1)
				h[i][j] = hcnt++;
			else
				h[i][j] = h[i - 1][j];
		}
	}
	graph = vector<vector<int> >(rcnt);
	match = vector<int >(hcnt, -1);
	check = vector<bool>(hcnt, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.') continue;
			int u = r[i][j];
			int v = h[i][j];
			graph[u].push_back(v);
		}
	}
	int ans = 0;
	for (int i = 0; i < rcnt; i++) {
		fill(check.begin(), check.end(), false);
		if (dfs(i))
			ans++;
	}
	cout << ans << endl;
}

