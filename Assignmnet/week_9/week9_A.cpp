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

int n, m, cnt ;
vector<vector<int> > graph;
set<int> ans;

int visited[20000];

int cutVertex(int here){
	visited[here] = ++cnt;
	int children = 0;
	int ret = visited[here];

	for (int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i];
		if (visited[there] == -1){
			children++;
			int mindepth = cutVertex(there);
			if (mindepth >= visited[here] && here != 0)
				ans.insert(here);
			ret = min(ret, mindepth);
		}
		else
			ret = min(ret, visited[there]);
	}
	if (here == 0 && children >= 2)
		ans.insert(here);
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		graph = vector<vector<int> >(n);
		ans.clear();
		memset(visited, -1, sizeof(visited));
		for (int i = 0; i < m; i++){
			int here, there;
			scanf("%d %d", &here, &there);
			graph[here].push_back(there);
			graph[there].push_back(here);
		}
		cnt = 0;
		cutVertex(0);
		for (set<int>::iterator itor = ans.begin() ; itor != ans.end(); itor++){
			cout << *itor << " ";
		}
		cout << endl;
	}
}