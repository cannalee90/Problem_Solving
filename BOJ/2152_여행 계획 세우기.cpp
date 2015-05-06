#include <iostream>
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
#include <functional>

typedef long long ll;
using namespace std;

int t, n, m;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	vector<vector<int > > graph(n + 1);
	for (int i = 0; i < m; i++){
		int here, there;
		cin >> here >> there;
		graph[here].push_back(there);
	}
	queue<int> que;
	que.push(s);
	vector<bool> visited(n + 1, false);
	int cnt = 1;

	while (!que.empty()){
		int here = que.front();
		que.pop();
		for (int i = 0; i < graph[here].size(); i++){
			int there = graph[here][i];
			if (visited[there] == false){
				visited[there] = true;
				if (there != t) cnt++;
				que.push(there);
			}
		}
	}
	if (visited[t] == false)
		cout << "0" << endl;
	else
		cout << cnt << endl;

}