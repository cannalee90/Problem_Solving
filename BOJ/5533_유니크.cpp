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
	int n;
	cin >> n;
	vector<int> rank(n, 0);
	vector<vector<int> > data(n, vector<int>(3, 0));
	for(int i = 0; i<n; i++)
	{
		scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
	}
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<n; j++)
		{
			int d = 0;
			for(int k = 0; k<n; k++)
			{
				if(k != j && data[k][i] == data[j][i])
				{ 
					d = 1; break;
				}
			}
			if(d == 0) rank[j] += data[j][i];
		}
	}
	for(int i = 0; i<n; i++)
	{
		cout << rank[i] << endl;
	}
}