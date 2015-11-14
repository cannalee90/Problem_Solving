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

int maze[110][110];
int visited[110][110];
int mmove[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int n, m;

bool isPossible(int h, int w){
	if (h < 1 || w < 1 || h > n || w > m) return false;
	return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	memset(visited, (1 << 6) - 1, sizeof(visited));
	queue<pair<int, int > > que;
	que.push(make_pair(1, 1));
	visited[1][1] = 0;
	while (!que.empty()) {
		int hereh = que.front().first;
		int herew = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nexth = hereh + mmove[i][0];
			int nextw = herew + mmove[i][1];
			if (isPossible(nexth, nextw) && visited[nexth][nextw] > visited[hereh][herew] + maze[nexth][nextw]) {
				visited[nexth][nextw] = visited[hereh][herew] + maze[nexth][nextw];
				que.push(make_pair(nexth, nextw));
			}
		}
	}
	cout << visited[n][m] << endl;
}
