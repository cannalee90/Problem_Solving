#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	long long d1[1010][3] = {0};
	long long t1[1010][3];
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> t1[i][0] >> t1[i][1] >> t1[i][2];
	}
	d1[0][0] = t1[0][0];
	d1[0][1] = t1[0][1];
	d1[0][2] = t1[0][2];
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<3; j++)
		{
			d1[i][j] += t1[i][j];
			long long min = 999999999999;
			for(int k = 0; k<3; k++)
			{
				if(j == k) continue;
				else
				{
					if(min > d1[i-1][k]) min = d1[i-1][k];
				}
			}
			d1[i][j] += min;
		}
	}
	long long min = 999999999999;
	for(int i = 0; i<3; i++)
	{
		if(d1[n-1][i] < min) min = d1[n-1][i];
	}
	cout << min;
}