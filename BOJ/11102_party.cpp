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

bool dfs(vector<vector<int> >& graph, vector<int>& match, vector<bool>& check, int here) {
	for (int next : graph[here]) {
		if (check[next]) continue;
		check[next] = true;
		if (match[next] == -1 || dfs(graph, match, check, match[next])) {
			match[next] = here;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		vector<vector<int> > graph(n);
		for (int i = 0; i < n; i++) {
			int q;
			cin >> q;
			for (int j = 0; j < q; j++) {
				int v;
				cin >> v;
				graph[i].push_back(v);
			}
		}
		vector<bool> last(m, false);
		vector<int> match(m, -1);
		int ans = 0;
		int cnt = 0;
		while (ans != m){
			cnt++;
			
			vector<bool> check(m, false);
			bool isChanged = false;
			for (int i = 0; i < n; i++) {
				fill(check.begin(), check.end(), false);
				if (dfs(graph, match, check, i)) {
					ans++;
					isChanged = true;
				}
			}
			if (!isChanged)
				break;
		}
		if (ans == m)
			cout << cnt << endl;
		else
			cout << "impossible" << endl;
	}
}

