#include <iostream>
#include <limits.h>
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


int num, n, m;
int mmax;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		cin >> num >> n >> m;

		vector<vector<bool> > graph(n + 1, vector<bool>(n + 1, false));

		for (int i = 0; i < m; i++){
			int h, t;
			cin >> h >> t;
			graph[h][t] = true;
		}
		vector<int> ans(n + 1, 0);
		vector<int> cnt(n + 1, 0);
		vector<bool> visited(n + 1, false);
		for (int i = 1; i <=n; i++){
			int vertex = n;
			for (int j = 1; j <= n; j++){
				if (visited[j]) 
					continue;
				bool indegree = false;
				for (int k = 1; k <= n; k++){
					if (graph[k][j] == true){
						indegree = true;
						break;
					}
				}
				if (!indegree){
					vertex = j;
					visited[vertex] = true;
					break;
				}
			}

			if (cnt[vertex] >= 2)
				ans[vertex] ++;
			for (int j = 1; j <= n; j++){
				if (graph[vertex][j] == true){
					graph[vertex][j] = false;
					if (ans[vertex] > ans[j]){
						cnt[j] = 1;	
						ans[j] = ans[vertex];
					}
					else if (ans[vertex] == ans[j]){
						cnt[j]++;
					}
				}
			}
		}
		printf("%d %d\n", num, ans[n] + 1);
	}
}