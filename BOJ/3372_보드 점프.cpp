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

int t;
int n;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long double a;
	cin >> a;
	couyt << a
		cin >> n;
		vector<vector<long double> > map(n + 1, vector<long double>(n + 1, 0));
		vector<vector<long double> > DP(n + 1, vector<long double>(n + 1, 0));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}
		}
		DP[1][1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] == 0) continue;
				int there_width = j + map[i][j];
				int there_height = i + map[i][j];
				if (there_width <= n) 
					DP[i][there_width] += DP[i][j];
				if (there_height <= n) 
					DP[there_height][j] += DP[i][j];
			}
		}
		if (DP[n][n]) cout << DP[n][n] << endl;

	
}