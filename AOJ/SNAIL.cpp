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


double Percent[2010][2010];


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n, m;
	cin >> t;
	while(t--)
	{	
		cin >> n;
		cin >> m;
		for(int i = 0; i<1010; i++)
		{
			for(int j = 0; j<1010; j++)
			{
				Percent[i][j] = 0;
			}
		}
		Percent[1][1] = 0.25;
		Percent[1][2] = 0.75;
		double result = 1;
		for(int i = 1; i<n; i++)
		{
			result -= Percent[m][i];
		}
		printf("%.10lf\n", result);
	}
}
