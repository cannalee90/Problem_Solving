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
	int t;
	int c = 1;
	cin >> t;

	while(t--)
	{
		ll n, t1;
		cin >> n;
		vector<ll> series;
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			series.push_back(t1);
		}
		while(series.size() > 2)
		{
			vector<ll> temp;
			int f = 0, r = series.size() - 1;
			while(f <= r)
			{
				temp.push_back(series[f++] + series[r--]);
			}
			series.clear();
			series = temp;
		}
		if(series[0] > series[1]) printf("Case #%d: Alice\n",c++);
		else printf("Case #%d: Bob\n", c++);
	}
}
