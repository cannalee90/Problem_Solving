#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

vector<vector<char> > data;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	vector<vector<long long > > DP(100, vector<long long>(11, 0));
	for (int i = 0; i <= 9; i++)
	{
		DP[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j <10; j++)
		{
			long long sum = 0; 
			if (j != 0) sum = DP[i][j - 1];
			DP[i][j] = sum + DP[i - 1][j];
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < 10; i++)
		{
			ans += DP[n][i];
		}
		cout << ans << endl;
	}

}
