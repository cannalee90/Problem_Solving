include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <functional>
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

vector<vector<char> > ground;
vector<vector<bool> > visited;

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int n, m;

inline bool isPossible(int h, int w, char team){
	if (h < 0 || w < 0 || h >= n || w >= m) return false;
	else if (visited[h][w] == true) return false;
	else if (ground[h][w] != team) return false;
	return true;
}

int dfs(int h, int w, char team){
	int ret = 0;
	for (int i = 0; i < 4; i++){
		int there_h = h + mmove[i][0];
		int there_w = w + mmove[i][1];
		if (isPossible(there_h, there_w, team)){
			visited[there_h][there_w] = true;
			ret += dfs(there_h, there_w, team);
		}
	}
	return ret + 1;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll ans_b = 0, ans_w = 0;
	cin >> m >> n;
	ground = vector<vector<char> >(n, vector<char>(m));
	visited = vector<vector<bool> >(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!visited[i][j]){
				visited[i][j] = true;
				ll cnt = dfs(i, j, ground[i][j]);
				if (ground[i][j] == 'B') ans_b += cnt * cnt;
				else 	ans_w += cnt * cnt;
			}
		}
	}
	cout << ans_w << " " << ans_b << endl;
}