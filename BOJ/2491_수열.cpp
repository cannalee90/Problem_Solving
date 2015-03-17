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
#define N 810

using namespace std;

typedef long long ll;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif

	ll n, t1;
	cin >> n;
	vector <ll> series;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		series.push_back(t1);
	}
	series.push_back(INF);
	int cnt = 1;
	int max = 0;
	for(int i = 0; i<n; i++)
	{
		if(max < cnt)
			max = cnt;
		if(series[i] <= series[i+1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}

	}
	cnt = 1;
	reverse(series.begin(), series.end() - 1);
	for(int i = 0; i<n; i++)
	{
		if(max < cnt)
			max = cnt;

		if(series[i] <= series[i+1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}
	}
	cout << max << endl;
}
