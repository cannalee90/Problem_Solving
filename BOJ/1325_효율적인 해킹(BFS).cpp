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

int n, m;
bool visited[10010];
vector<vector<int> > graph;

int bfs(int vertex){
	int ans = 1;
	queue<int> que;
	que.push(vertex);
	visited[vertex] = true;
	while (!que.empty()){
		int here = que.front();
		que.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i];
			if (visited[there] == false){
				visited[there] = true;
				ans++;
				que.push(there);
			}
		}
	}
	return ans;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	graph.resize(n + 1);
	for (int i = 0; i < m; i++){
		int t, h;
		scanf("%d %d", &t, &h);
		graph[h].push_back(t);
	}
	int mmax = -1;
	vector<int>res;

	for (int i = 1; i <= n; i++){
		int t = bfs(i);
		if (mmax < t){
			mmax = t;
			res.clear();
			res.push_back(i);
		}else if (mmax == t){
			res.push_back(i);
		}
		memset(visited, false, sizeof(visited));
	}
	for (int i = 0; i < res.size(); i++){
		printf("%d ", res[i]);
	}
	printf("\n");
}