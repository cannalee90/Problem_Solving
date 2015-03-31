#include <iostream>
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

int n, m;
vector<int> indegree;
vector<vector<int> > graph;
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int> > pq;
	indegree.resize(n + 1, 0);
	graph.resize(n + 1);
	for (int i = 0; i <m; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		graph[t1].push_back(t2);
		indegree[t2]++;
	}
	for (int i = 1; i <= n; i++){
		if (!indegree[i])
			pq.push(i);
	}

	while (!pq.empty()){
		int cur = pq.top();
		pq.pop();
		printf("%d ", cur);
		for (int i = 0; i < graph[cur].size(); i++){
			int out = graph[cur][i];
			indegree[out]--;
			if (!indegree[out])
				pq.push(out);
		}
	}
	cout << endl;
}