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

int n, m, start;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n >> start >> m;
	vector<int> volumes;
	vector<vector<int> > DP(n + 1, vector<int>(m + 1, -2));
	for(int i = 0; i<n; i++)
	{
		int t1;
		cin >> t1;
		volumes.push_back(t1);
	}
	DP[0][start] = -1;
	for(int i = 0; i<n; i++)
	{
		int volume = volumes[i];
		for(int j = 0; j<=m; j++)
		{
			if(DP[i][j] == i - 1)
			{
				if(j + volume <= m)
					DP[i + 1][j + volume] = i;
				if(j - volume >= 0)
					DP[i + 1][j - volume] = i;
			}
		}
	}
	for(int i= m; i>=0; i--)
	{
		if(DP[n][i] == n-1)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}
