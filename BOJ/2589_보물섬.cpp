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

const char M = 101;

int n, m;
char map[M][M];
int mmove[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

class path
{
public:
	path(int height, int width, int length)
	{
		this->height = height;
		this->width = width;
		this->length = length;
	}
	int height;
	int width;
	int length;
};

int coor(int height, int width)
{
	if(height > n || height < 1) return 1;
	if(width > m || width < 1 ) return 1;
	return 0;
}


int bfs(int height, int width)
{
	int check[M][M];
	int max = 0;
	for(int i = 0; i<=n+1; i++)
	{
		for(int j = 0; j<=m+1; j++)
		{
			check[i][j] = 99999;
		}
	}
	queue<path> que;
	que.push(path(height, width, 0));
	check[height][width] = 0;
	while(!que.empty())
	{
		path here = que.front();
		for(int i = 0; i<4; i++)
		{
			if(map[here.height + mmove[i][0]][here.width + mmove[i][1]] != 'L') continue;
			if(coor(here.height + mmove[i][0], here.width + mmove[i][1])) continue;
			if(check[here.height + mmove[i][0]][here.width + mmove[i][1]] <= here.length + 1) continue;
			que.push(path(here.height + mmove[i][0], here.width + mmove[i][1], here.length + 1));
			check[here.height + mmove[i][0]][here.width + mmove[i][1]] = here.length + 1;
			if(here.length + 1 > max) max = here.length + 1;
		}
		que.pop();
	}
	return max;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t; 
	int max = 0;
	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> map[i][j];
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(map[i][j] == 'L')
			{
				t = bfs(i,j);
				if(t > max) max = t;
			}
		}
	}
	cout << max << endl;
}