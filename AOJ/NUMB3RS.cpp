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

int map[110][100];
double percent[110][100];
int connect[110];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n, days, start, m;
	int t1;
	cin >> t;
	while(t--)
	{
		cin >> n >> days >> start;
		for(int i = 0; i<100; i++)
		{
			for(int j = 0; j<100; j++)
			{
				map[i][j] = 0;
				percent[i][j] = 0;
				connect[i] = 0;
			}
		}
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				cin >> t1;
				map[i][j] = t1;
				if(t1 == 1)
					connect[i]++;
			}
		}
		for(int i = 0; i<n; i++)
		{
			if(map[start][i] == 1)
			{
				percent[0][i] = 1 / (double)connect[start];
			}
		}
		for(int i = 1; i<days; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(percent[i-1][j] != 0)
				{
					for(int k = 0; k<n; k++)
					{
						if(map[j][k] == 1)
						{
							percent[i][k] += percent[i-1][j] / (double)connect[j];
//							cout << percent[i-1][j] << " " << (double)connect[j] << endl;
						}
					}
				}
			}
		}
		cin >> m;
		for(int i = 0; i<m; i++)
		{
			cin >> t1;
			printf("%.10lf ", percent[days-1][t1]);
		}
		printf("\n");
	}
}
