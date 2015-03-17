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

const int M = 1010;

int n;
int m;

int map[M][M];
int path[M];

bool bfs(int begin, int end)
{
	int check[M] = {0};
	queue<int> que;
	que.push(begin);
	check[begin] = 1;
	while(!que.empty())
	{
		int here = que.front();
		if(here == end) return 0;
		for(int i = 1; i<=n; i++)
		{
			if(map[here][i] == 0) continue;
			if(check[i] == 1)
				continue;
			else
			{
				check[i] = 1;
				que.push(i);
			}
		}
		que.pop();
	}
	return 1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	cin >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			cin >> map[i][j];
		}
	}
	for(int j = 1; j<=m; j++)
	{
		cin >> path[j];
	}
	for(int j = 1; j<m; j++)
	{
		if(bfs(path[j], path[j+1])) {cout << "NO" << endl; return 0;}
	}
	cout << "YES" << endl;
}