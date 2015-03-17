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

	char map[1100][1100];
	int n, m;

bool Ispossible(int height, int width, int k)
{
	if(height + k > n || width + k > m) return 1;
	for(int i = 0; i<=k; i++)
	{
		for(int j = 0; j<=k; j++)
		{
			if(map[height + i][width + j] != map[height][width]) return 1;
		}
	}
	return 0;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif

	cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> map[i][j];
		}
	}
	int max = 0;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			int k = max;
			if(map[i][j] == '0') continue;
			while(1)
			{

				if(Ispossible(i, j, k)) break;
				k++;
			}
			if(max < k) max = k;
		}
	}
	cout << (max) * (max);
}