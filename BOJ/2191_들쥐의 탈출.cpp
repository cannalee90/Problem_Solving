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

bool getDis(double x1, double y1, double x2, double y2, int s, int v) {
	double dis = sqrt(abs(x2 - x1) * abs(x2 - x1) + abs(y2 - y1) * abs(y2 - y1));
	if (s * v >= dis) 
		return true;
	else 
		return false;
}

bool dfs(int here, vector<vector<int> >& graph, vector<bool>& check, vector<int>& match){
	for (int& next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(match[next], graph, check, match)) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin); 	//이분매칭
	int n, m, s, v;						//한쪽 그래프는 쥐, 한쪽 그래프는 굴
	cin >> n >> m >> s >> v;
	vector<pair<double, double > > mice(n);
	vector<pair<double, double > > cave(m);

	for (int i = 0; i < n; i++)
		cin >> mice[i].first >> mice[i].second;
	for (int j = 0; j < m; j++)
		cin >> cave[j].first >> cave[j].second;

	vector<vector<int> > graph(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (getDis(mice[i].first, mice[i].second, cave[j].first, cave[j].second, s, v)) {
				graph[i].push_back(j);
			}
		}
	}

	vector<int> match(m, -1);
	vector<bool> check(m);
	int ans = 0;

	for (int i = 0; i < n; i++) {
		fill(check.begin(), check.end(), false);
		if (dfs(i, graph, check, match))
			ans++;
	}
	cout << n - ans << endl;
}
