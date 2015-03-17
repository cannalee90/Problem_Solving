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
	int n, t1;
	vector<int> data;
	cin >> n;
	long long DP[100][21] = {0};
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		data.push_back(t1);
	}
	DP[0][data[0]] = 1;
	for(int i =1; i<=n - 2; i++)
	{
		for(int j = 0; j<=20; j++)
		{
			if(j - data[i] >= 0) DP[i][j] += DP[i-1][j - data[i]];
			if(j + data[i] <= 20) DP[i][j] += DP[i-1][j + data[i]];
		}
	}
	printf("%lld\n",DP[n-2][data[n-1]]);
}
