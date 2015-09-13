#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
int camera = 0;

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int last, int here){
	if (graph[here].size() == 0) return;
	for (int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if (last != there){
			dfs(graph, visited, here, there);
			if (!visited[there]){
				camera++;
				for (int i = 0; i < graph[here].size(); i++){
					if (!visited[graph[here][i]])	visited[graph[here][i]] = true;
				}
				visited[here] = true;
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t, n, m;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		vector<vector<int> > graph(n);
		vector<bool> visited(n, false);
		for (int i = 0; i < m; i++){
			int t, h;
			scanf("%d %d", &t, &h);
			graph[t].push_back(h);
			graph[h].push_back(t);
		}
		camera = 0;
		for (int i = 0; i < n; i++){
			if (!visited[i]){
				dfs(graph, visited, i, i);
				if (!visited[i]){
					camera++;
					visited[i] = true;
				}
			}
		}
		cout << camera << endl;
	}
}