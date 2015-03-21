#include <iostream>
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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int mmax = 0;
	int t;
	cin >> t;
	while (t--)
	{
		int den;
		cin >> n >> m;
		vector<vector<int> > graph(n + 1);
		vector<int> cost(n + 1);
		vector<int> indegree(n + 1);
		vector<int> visited(n + 1, 0);
		queue<int> que;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &cost[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			int t1, t2, t3;
			scanf("%d %d", &t1, &t2);
			graph[t1].push_back(t2);
			indegree[t2]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!indegree[i])
			{
				que.push(i);
				visited[i] = cost[i];
			}
		}
		cin >> den;
		while (!que.empty())
		{
			int here = que.front();
			que.pop();
			for (int i = 0; i<graph[here].size(); i++)
			{
				int there = graph[here][i];
				if (visited[there] < cost[there] + visited[here])
				{
					que.push(graph[here][i]);
					visited[there] = cost[there] + visited[here];
				}
			}
		}
		cout << visited[den] << endl;
	}
}