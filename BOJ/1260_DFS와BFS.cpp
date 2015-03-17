#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int n, m, start;

vector< vector<int> > graph(1000 + 1, vector<int> (1000 + 1));
vector< int > visited (1000 + 1);
string result = "";


void dfs(long long  here)
{
	result += to_string(here) + " ";
	visited[here] = 1;
	for(int i = 1; i<=n; i++)
	{
		if(graph[here][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}

void bfs(long long start)
{
	long long here;
	vector< int > visited (1000 + 1);
	result = "";
	queue <int> que;
	que.push(start);
	while(!que.empty())
	{
		here = que.front();
		if(visited[here] == 0)
			result += to_string(here) + " ";
		visited[here] = 1;
		for(int i = 1; i<=n; i++)
		{
			if(graph[here][i] == 1 && visited[i] == 0)
			{
				que.push(i);
			}
		}
		que.pop();
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, t2,t3;
	cin >> n >> m >> start;

	for(int i = 0; i<m; i++)
	{
		cin >> t1 >> t2;
		graph[t1][t2] = 1;
		graph[t2][t1] = 1;
	}
	dfs(start);
	cout << result << endl;
	bfs(start);
	cout << result << endl;

}