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

vector<int> work;
vector<bool> check;
vector<vector<int > > graph;

bool dfs(int here) {
	for (int i = 0; i < graph[here].size(); i++) {
		int there = graph[here][i];
		if (check[there]) 
			continue;
		else {
			check[there] = true;
			if (work[there] == -1 || dfs(work[there])) {
				work[there] = here;
				return true;
			}
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	graph.assign(n + 1, vector<int>());
	work.assign(m + 1, -1);
	check.assign(m + 1, false);
	for (int i = 1; i <= n; i++) {
		int job;
		cin >> job;
		for (int j = 0; j < job; j++) {
			int num;
			cin >> num;
			graph[i].push_back(num);
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			fill(check.begin(), check.end(), false);
			if (dfs(i))
				ans++;
		}
	}
	cout << ans << endl;
}
