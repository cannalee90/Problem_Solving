#include <iostream>
#include <climits>
#include <functional>
#include <utility>
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

int n, m, t;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	string str;
	cin >> t;
	while (t--){
		cin >> n >> m;

		int indegree[30] = {}, outdegree[30] = {};
		vector<vector<int> > graph(n);
		priority_queue<int, vector<int>, greater<int> > pq;

		for (int i = 0; i < m; i++){
			cin >> str;
			indegree[str[1] - 'A']++;
			graph[str[0] - 'A'].push_back(str[1] - 'A');
		}

		for (int i = 0; i < n; i++){
			if (indegree[i] == 0)
				pq.push(i);
		}

		while (!pq.empty()){
			int cur = pq.top();
			pq.pop();
			printf("%c", cur + 'A');
			for (int i = 0; i < graph[cur].size(); i++){
				int there = graph[cur][i];
				indegree[there]--;
				if (indegree[there] == 0)
					pq.push(there);
			}
		}
		printf("\n");
	}
}
