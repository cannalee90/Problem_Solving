
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

int n;

ll mmax(int a, int b, int c)
{
	int mx;
	if( a > b) mx = a;
	else mx = b;
	if(mx > c) return mx;
	else return c;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	
	ll data[10000 + 1] = {0};
	ll DP[3][10000 + 1] = {0};

	for(int i = 1; i<=n; i++)
	{
		cin >> data[i];
	}

	DP[0][1] = data[1];

	if(n > 1)
	{
		DP[0][2] = data[2];
		DP[1][2] = data[1] + data[2];
		DP[2][2] = max(DP[0][1], DP[1][1]);
	}

	ll maxx = 0;

	for(int i = 3; i<=n; i++)
	{

		DP[0][i] = mmax(DP[0][i-2],DP[1][i-2],DP[2][i-2]) + data[i];
		DP[1][i] = mmax(DP[0][i-3],DP[1][i-3],DP[2][i-2]) + data[i] + data[i-1];
		DP[2][i] = mmax(DP[0][i-1],DP[1][i-1],DP[2][i-1]);
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<3; j++)
		{
			maxx = max(DP[j][i], maxx);
		}
	}
	cout << maxx << endl;
}
