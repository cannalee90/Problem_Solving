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

char map[54][54];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n, m;
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
			int k = 0;
			int cnt = 0;
			while(1)
			{
				if(i + k > n || j + k > m) break;
				if(map[i][j] == map[i+k][j] && map[i][j] == map[i][j+k] && map[i][j] == map[i+k][j+k]) cnt = k;
				k++;
			}
			if(max < cnt) max = cnt;
		}
	}
	cout << (max +1)* (max+1) << endl;
}