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

const int M = 60;

int check[1010];
int series[100];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	int m;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> series[i];
		check[series[i]] = 1;
	}
	sort(series, series+n);
	int begin = 1;
	int index = series[0];
	cin >> m;
	for(int i = 0; i<n; i++)
	{
		if(series[i] < m && series[i+1] > m)
		{
			index = series[i+1];
			begin = series[i];
		}
	}
	long long cnt = 0;
	for(int k = begin; k<=index; k++)
	{
		if(k > m ) break;
		if(check[k]) continue;
		for(int i = k+1; i<=series[n-1]; i++)
		{
			if(!check[i])
			{
				if(i >= m)
					cnt++;
			}
			else 
				break;
		}
	}
	cout << cnt << endl;
}