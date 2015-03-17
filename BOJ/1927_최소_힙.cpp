#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 9223372036854775807

using namespace std;

typedef long long ll;



int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll n, m;
	cin >> n;
	priority_queue <ll, vector<ll>, greater<ll> > que;
	while(n--)
	{
		cin >> m;
		if(m == 0)
		{
			if(que.empty())
			{
				cout << "0" << endl;
			}
			else
			{
				cout << que.top() << endl;
				que.pop();
			}
		}
		else
		{
			que.push(m);
		}
	}
}
