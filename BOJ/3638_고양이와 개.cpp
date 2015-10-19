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

vector<int> slice;
vector<bool> check;
vector<vector<int> > graph;

bool dfs(int here) {
	for (int next : graph[here]) {
		if (check[next]) continue;
		else {
			check[next] = true;
			if (slice[next] == -1 || dfs(slice[next])) {
				slice[next] = here;
				return true;
			}
		}
	}
	return false;
}

bool sliceMatch(int m, int n) {
	for (int i = 0; i < 100; i++) {
		fill(check.begin(), check.end(), false);
		dfs(i);
		bool isDone = true;
		for (int j = 1; j <= m; j++) {
			if (slice[j] == -1) {
				isDone = false;
				break;
			}
		}
		if (isDone) {
			cout << i + 1 << endl;
			return true;
		}
	}
	return false;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		slice.assign(m + 1, -1);
		graph.assign(101, vector<int>());
		check.assign(m + 1, false);
		for (int i = 0; i < n; i++) {
			int begin, end, num;
			cin >> begin >> end >> num;
			for (int k = 0; k < num; k++) {
				int des;
				cin >> des;
				for (int j = begin; j < end; j++) {
					graph[j].push_back(des);
				}
			}
		}
		if (!sliceMatch(m, n))
			cout << "-1" << endl;
	}
}