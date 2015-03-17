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

int ans;
int t, n , m;

void brute_force(int lottery, int cnt)
{
	if(cnt == n){ ans++; return;}
	if(lottery >= m) return;
	for(int i = lottery * 2; i<= m; i++)
	{
		brute_force(i, cnt + 1);
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		ans = 0;
		for(int i = 1; i<=10; i++)
		{
			brute_force(i, 1);
		}
		cout << ans << endl;
	}
/*
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > DP(n + 1,vector<int>(m + 1, 0));
		for(int i = 1; i<=m; i++)
		{
			DP[1][i] = i;
		}
		for(int i = 2; i<=n; i++)
		{
			for(int j = pow((double)2, i-1); j<=m; j++)
			{
				int idx = j - 1;
				while(idx > 0)
				{
					DP[i][j] += DP[i-1][idx];
					idx -= 2;
				}
			}
		}
		cout << DP[n][m] << endl;
	}
	*/
}
