#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include<list>

#define INF 900000000

using namespace std;

typedef long long ll;

bool check[500001];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll n, cnt = 0, loop = 1;
	ll t1;
	int min = 1;
	cin >> n;
	while(1)
	{
		int d = 0;
		t1 = pow(2, (double)loop);
		if((n - cnt) % 2 == 1) d = 1;
		for(int i = min; i<=n; i+=t1)
		{
			check[i] = 1;
			cnt++;
			if(n - cnt ==1) break;
		}
		if(n - cnt ==1) break;
		if(d == 0)
		{
			for(int i = 1; i<=n; i++)
			{
				if(check[i] == 0) 
				{
					min = i;
					break;
				}
			}
		}
		else
		{
			d = 0;
			for(int i = 1; i<=n; i++)
			{
				if(check[i] ==1)
				{
					if(d == 0) {d = 1; continue;}
					else
					{
						min = 1; break;
					}
				}
			}
		}
		loop++;
	}
	for(int i = 1; i<=n; i++)
	{
		if(check[i] == 0) {cout << i << endl; break;}
	}

}
