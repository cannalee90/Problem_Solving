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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<vector<int> > graph(n + 1);

	while (1){
		int t, h;
		scanf("%d %d", &t, &h);
		if (t == -1 && h == -1)
			break;
		else{
			graph[h].push_back(t);
			graph[t].push_back(h);
		}
	}

	int mmin = INT_MAX;
	vector<int> res;
	for (int i = 1; i <= n; i++){
		vector<int> visited(n + 1, INT_MAX);
		visited[i] = 0;
		queue<int> que;
		que.push(i);
		while (!que.empty()){
			int here = que.front();
			que.pop();
			for (int i = 0; i < graph[here].size(); i++){
				int there = graph[here][i];
				if (visited[there] > visited[here] + 1){
					visited[there] = visited[here] + 1;
					que.push(there);
				}
			}
		}
		vector<int>::iterator itor = max_element(visited.begin() + 1, visited.end());
		if (mmin > *itor){
			res.clear();
			res.push_back(i);
			mmin = *itor;
		}else if (mmin == *itor){
			res.push_back(i);
		}
	}
	printf("%d %d\n", mmin, res.size());
	for (int i = 0; i < res.size(); i++){
		printf("%d ", res[i]);
	}
	printf("\n");
}