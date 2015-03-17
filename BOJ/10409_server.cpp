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
	ll n, m, limit, total = 0, t1;
	ll cnt = 0;
	scanf("%lld %lld",&n, &limit);
	queue<ll> que;
	for(int i = 0; i<n; i++)
	{
		scanf("%lld", &t1);
		que.push(t1);
	}
	while(!que.empty())
	{
		if(total + que.front() <= limit)
		{
			total += que.front();
			cnt ++;
			que.pop();
		}
		else
		{
			break;
		}
	}
	cout << cnt << endl;
}
