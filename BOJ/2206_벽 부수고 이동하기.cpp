#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include<functional>
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
char ground[2001][2001];
int visited[2][2001][2001];
int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int n, m;


inline bool isPossible(int h, int w, int cost, int wall){
	if (h > n || h < 1 || w > m || w < 1) return false;
	if (visited[wall][h][w] <= cost) return false;
	if (wall == 1 && ground[h][w] == '1') return false;
	return true;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> ground[i][j];
			visited[0][i][j] = INT_MAX;
			visited[1][i][j] = INT_MAX;
		}
	}
	priority_queue<pair<int, pair<int, pair<int, int > > >, vector<pair<int, pair<int, pair<int, int > > > >, greater<pair<int, pair<int, pair<int, int > > > > > pq;
	pq.push(make_pair(1, make_pair(0, make_pair(1, 1))));
	visited[0][1][1] = 1;
	visited[1][1][1] = 1;
	while (!pq.empty()){
		int here_cost = pq.top().first;
		int here_wall = pq.top().second.first;
		int	here_h = pq.top().second.second.first;
		int here_w = pq.top().second.second.second;
		pq.pop();
		if (visited[here_wall][here_h][here_w] < here_cost) continue;
		for (int i = 0; i < 4; i++){
			int there_h = here_h + mmove[i][0];
			int there_w = here_w + mmove[i][1];
			int there_wall = ground[there_h][there_w] - '0' + here_wall;
			if (isPossible(there_h, there_w, here_cost, here_wall)){
				visited[there_wall][there_h][there_w] = here_cost + 1;
				pq.push(make_pair(here_cost + 1, make_pair(there_wall, make_pair(there_h, there_w))));
			}
		}
	}
	printf("%d\n", min(visited[0][n][m], visited[1][n][m]));
}