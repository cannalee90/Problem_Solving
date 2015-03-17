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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	
	ll data[10000 + 1] = {0};
	ll DP[2][10000 + 1] = {0};

	for(int i = 1; i<=n; i++)
	{
		cin >> data[i];
	}

	DP[0][1] = data[1];

	if(n > 1)
	{
		DP[0][2] = data[2];
		DP[1][2] = data[1] + data[2];
	}

	ll maxx = 0;

	for(int i = 3; i<=n; i++)
	{
		DP[0][i] = max(DP[0][i-2],DP[1][i-2]) + data[i];
		DP[1][i] = max(DP[0][i-3],DP[1][i-3]) + data[i] + data[i-1];
	}
	cout << max(DP[0][n], DP[1][n]) << endl;
}
