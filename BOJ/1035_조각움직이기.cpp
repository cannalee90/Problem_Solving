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
 
char map[8][8];
int d1[6][2];
int M[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int check[8][8];
int coorxy[8][2];
int series[8];
int totalmin = 999999999;
int NoP =1;
int countT;
int rcoorxy[8][2];

int coor(int height, int width)
{
    if(height > 5 || width > 5) return 1;
    if(height < 1 || width < 1) return 1;
    return 0;
}
 
void Findmin(int index, int length)
{
	if(series[index]) return;
	series[index] = length;
	if(length == NoP)
	{
		int total = 0;
		for(int i = 1; i<=NoP; i++)
		{
			total += abs(coorxy[i][0] - d1[series[i]][0]);
			total += abs(coorxy[i][1] - d1[series[i]][1]);
		}
		if(totalmin > total)
		{
			totalmin = total;
			for(int i= 1; i<=NoP; i++)
			{
				rcoorxy[i][0] = coorxy[i][0];
				rcoorxy[i][1] = coorxy[i][1];

			}
		}
	}
	for(int i = 1; i<=NoP; i++)
	{
		if(series[i]!= 0) continue;
		Findmin(i, length + 1);
	}
	series[index] = 0;
}

void dfs(int height, int width, int length)
{
	if(check[height][width] == 0)
	{
		check[height][width] = 1;
		coorxy[length][0] = height;
		coorxy[length][1] = width;
	}
	else if(check[height][width] == 1)
	{
		for(int i = 0; i<4; i++)
		{
			if(coor(height + M[i][0], width + M[i][1])) continue;
			if(check[height + M[i][0]][width + M[i][1]] == 0)
				dfs(height + M[i][0], width + M[i][1], length + 1);
		}
		return;
	}
	if(length == NoP)
	{
		countT++;
		for(int i = 1; i<=NoP; i++)
		{
			Findmin(i,1);
		}
		check[height][width] = 0;
		coorxy[length][0] = 0;
		coorxy[length][1] = 0;
		return ;
	}
	for(int i = 0; i<4; i++)
	{
		if(coor(height + M[i][0], width + M[i][1])) continue;
		if(check[height + M[i][0]][width + M[i][1]] == 0)
			dfs(height + M[i][0], width + M[i][1], length + 1);
		else
			dfs(height + M[i][0], width + M[i][1], length);

	}
	check[height][width] = 0;
	coorxy[length+1][0] = 0;
	coorxy[length+1][1] = 0;

}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    int n = 5;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == '*')
            {
                d1[NoP][0] = i;
				d1[NoP++][1] = j;
            }
        }
    }
	NoP--;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			dfs(i, j, 1);
		}
	}
	cout << totalmin << endl;; 
}
