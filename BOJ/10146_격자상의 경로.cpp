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
	int h, w, mh, mw, t1;
	int DP[20][20] = {0};
	int DP_F[20][20] = {0};
	cin >> h >> w >> t1;
	mh =  t1 / w + 1;
	mw = t1 % w;
	if(mw == 0) mw = w, mh = mh - 1;
	DP[1][1] = 1;
	for(int i = 1; i<=h; i++)
	{
		for(int j = 1; j<=w; j++)
		{
			DP[i+1][j] += DP[i][j];
			DP[i][j+1] += DP[i][j];
		}
	}
	if(t1 != 0)
	{
		DP_F[mh][mw] = DP[mh][mw];
		for(int i = 1; i<=h; i++)
		{
			for(int j = 1; j<=w; j++)
			{
				DP_F[i+1][j] += DP_F[i][j];
				DP_F[i][j+1] += DP_F[i][j];
			}
		}
		cout << DP_F[h][w] << endl;
	}
	else
	{
		cout << DP[h][w] << endl;
	}
}
