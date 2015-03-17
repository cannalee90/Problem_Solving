#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n, t;
	cin >> t;
	while(t--)
	{
		int map[110][110];
		int DP[110][110];
		int path[110][110];
		cin >> n;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<=i; j++)
			{
				cin >> map[i][j];
				DP[i][j] = -1;
				path[i][j] = 0;
			}
		}
		for(int i = 0; i<n; i++)
		{
			DP[n-1][i] = map[n-1][i];
			path[n-1][i] = 1;
		}
		for(int i = n - 2; i>= 0; i--)
		{
			for(int j = 0; j<=i; j++)
			{
				if(DP[i][j] < DP[i + 1][j])
				{
					DP[i][j] = DP[i + 1][j] + map[i][j];
					path[i][j] = path[i+1][j];
				}
				if(DP[i+1][j] < DP[i + 1][j + 1])
				{
					DP[i][j] = DP[i + 1][j + 1] + map[i][j];
					path[i][j] = path[i+1][j + 1];

				}
				if(DP[i+1][j] == DP[i+1][j +1])
				{
					path[i][j] += path[i+1][j+1];
				}
			}
		}
		cout << path[0][0] << endl;
	}
}
