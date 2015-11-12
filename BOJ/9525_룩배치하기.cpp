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

vector<bool> check;
vector<int> match;

bool dfs(vector<vector<int> > &graph, int here) {
	for (int next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(graph, match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	
	int n;
	char board[110][100] = {};
	int row[110][100] = {};
	int col[110][110] = {};
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	int rcnt = 1;
	int ccnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '.') continue;
			if (j == 0 || row[i][j - 1] == 0)
				row[i][j] = rcnt++;
			else if(row[i][j-1] != 0)
				row[i][j] = row[i][j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[j][i] != '.') continue;
			if (j == 0 || col[j - 1][i] == 0)
				col[j][i] = ccnt++;
			else if (col[j - 1][i] != 0)
				col[j][i] = col[j - 1][i];

		}
	}
	
	vector<vector<int> > graph(rcnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '.') continue;
			int u = row[i][j];
			int v = col[i][j];
			graph[u].push_back(v);
		}
	}
	check.assign(ccnt, false);
	match.assign(ccnt, -1);
	int ans = 0;
	for (int i = 1; i < rcnt; i++) {
		fill(check.begin(), check.end(), false);
		if (dfs(graph, i))
			ans++;
	}
	cout << ans << endl;
}

