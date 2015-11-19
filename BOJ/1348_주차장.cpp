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
int n, m;


bool isPossible(int h, int w) {
	if (h < 0 || w < 0 || h >= n || w >= m) return false;
	return true;
}

vector<vector<int> > bfs(  vector<vector<char> >& ground, int h, int w) {
	int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	queue<pair<int, int > > que;
	vector<vector<int > > visited(110, vector<int>(110, INF));
	visited[h][w] = 0;
	que.push(make_pair(h, w));
	while (!que.empty()) {
		int here_h = que.front().first;
		int here_w = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int next_h = here_h + mmove[i][0];
			int next_w = here_w + mmove[i][1];
			int next_cnt = visited[here_h][here_w] + 1;
			if (isPossible(next_h, next_w) && ground[next_h][next_w] != 'X' && visited[next_h][next_w] > next_cnt) {
				que.push(make_pair(next_h, next_w));
				visited[next_h][next_w] = next_cnt;
			}
		}
	}
	return visited;
}


bool dfs(  vector<vector<pair<int, int > > >& graph, vector<int>& match, vector<bool>& check, int here, int mid) {
	for (auto next : graph[here]) {
		if (next.second > mid) continue;
		if (check[next.first]) continue;
		check[next.first] = true;
		if (match[next.first] == -1 || dfs(graph, match, check, match[next.first], mid)) {
			match[next.first] = here;
			return true;
		}
	}
	return false;
}

bool isReachable(  int mid,   vector < vector<pair<int, int > > >& graph,   int cars,   int parks) {
	vector<bool> check(parks, false);
	vector<int> match(parks, -1);
	for (int i = 0; i < cars; i++) {
		fill(check.begin(), check.end(), false);
		dfs(graph, match, check, i, mid);
	}
	int cnt = 0;
	for (int i = 0; i < parks; i++)  {
		if (match[i] != -1)
			cnt++;
	}
	return cnt == cars;
}

int main(){
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	vector<vector<char> >  ground(110, vector<char>(110));
	vector< pair<int, int > > car;
	vector< pair<int, int > > park;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char cur;
			cin >> ground[i][j];
			if (ground[i][j] == 'C'){
				car.push_back(make_pair(i, j));
			}
			else if (ground[i][j] == 'P'){
				park.push_back(make_pair(i, j));
			}
		}
	}
	vector < vector<pair<int, int > > > graph(car.size());
	if (car.size() == 0) {
		cout << "0" << endl;
		exit(0);
	}
	if (park.size() < car.size()) {
		cout << "-1" << endl;
		exit(0);
	}
	for (int i = 0; i < car.size(); i++) {
		auto tmp = bfs(ground, car[i].first, car[i].second);
		for (int idx = 0; idx < park.size(); idx++){
			for (int j = 0; j < n && idx < park.size(); j++) {
				for (int k = 0; k < m && idx < park.size(); k++){
					if (j == park[idx].first && k == park[idx].second) {
						graph[i].push_back(make_pair(idx, tmp[j][k]));
					}
				}
			}
		}
	}
	int left = 0, right = 10000;
	int ans = -1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (isReachable(mid, graph, car.size(), park.size())){
			right = mid - 1;

			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << endl;
}

