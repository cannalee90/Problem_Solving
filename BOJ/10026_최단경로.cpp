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

int mmove[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int n;

char map[110][110];
char map1[110][110];


class path
{
public:
	path(int height, int width)
	{
		this->height = height;
		this->width = width;
	}
	int height;
	int width;
};

bool coor(int height, int width)
{
	if(height < 1 || height > n ) return 1;
	if(width < 1 || width > n) return 1;
	return 0;
}

void bfs1( int height, int width, char a)
{
	queue<path> que;
	que.push(path(height, width));
	map[height][width] = '.';
	while(!que.empty())
	{
		path P = que.front();
		for(int i = 0; i<4; i++)
		{
			if(coor(P.height + mmove[i][0], P.width + mmove[i][1])) continue;
			if(map[P.height + mmove[i][0]][ P.width + mmove[i][1]] != a) continue;
			que.push(path(P.height + mmove[i][0], P.width + mmove[i][1]));
			map[P.height + mmove[i][0]][P.width + mmove[i][1]] = '.';
		}
		que.pop();
	}
}

void bfs2( int height, int width, char a)
{
	queue<path> que;
	que.push(path(height, width));
	map1[height][width] = '.';
	while(!que.empty())
	{
		path P = que.front();
		for(int i = 0; i<4; i++)
		{
			if(coor(P.height + mmove[i][0], P.width + mmove[i][1])) continue;
			if(map1[P.height + mmove[i][0]][ P.width + mmove[i][1]] != a) continue;
			que.push(path(P.height + mmove[i][0], P.width + mmove[i][1]));
			map1[P.height + mmove[i][0]][P.width + mmove[i][1]] = '.';
		}
		que.pop();
	}
}

int main()
{

int c1 =0;
int c2 = 0;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			cin >> map[i][j];
			map1[i][j] = map[i][j];
			if(map[i][j] == 'R') map1[i][j] = 'G';
		}
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(map[i][j] != '.')
			{
				bfs1( i, j, map[i][j]);
				c1 ++;
			}
			if(map1[i][j] != '.')
			{
				bfs2( i, j, map1[i][j]);
				c2++;
			}
		}
	}
	cout << c1 << " " << c2 << endl;
}