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

using namespace std;

typedef long long ll;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll n, d, k, c;
	ll t1,t2;
	int check[3010] = {0};
	cin >> n >> d >> k >> c;
	vector<ll> series;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		series.push_back(t1);
	}
	int index = 0;
	for(int i = n; i<n + k; i++)
	{
		series.push_back(series[index++]);
	}
	int ns = 0;
	check[c] = 1;
	int cnt = 1;
	int max = 1;
	queue<ll> que;
	for(int i = 0; i<n + k; i++)
	{
		int plate = series[i];
		if(que.size() < k)
		{
			if(check[plate] == 0)
			{
				cnt++;
			}
			check[plate]++;
			que.push(plate);
		}
		else
		{
			if(check[plate] == 0) cnt ++;
			check[que.front()]--;
			check[plate]++;
			if(check[que.front()] == 0) cnt--;
			que.push(plate);
			que.pop();
		}
		if(max < cnt)
		{
			max = cnt;
		}
	}
	cout << max << endl;
}
