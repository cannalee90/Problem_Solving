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

ll n, m;
ll prime;
bool era[1000100];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll total = 0;
	scanf("%d %d", &n, &m);
	prime = 3;
	if(n <= 2) printf("2\n");
	ll limit = sqrt((double)m);
	while(prime <= limit)
	{
		for(int i = prime*2; i<=m; i+=prime)
		{
			era[i] = 1;
		}
		for(int i = prime+1; i<=m; ++i)
		{
			if(i % 2 != 0&&era[i] == 0)
			{
				prime = i;
				break;
			}
		}
	}
	for(int i = n; i<=m; ++i)
	{
		if(!era[i] && i % 2)
			printf("%d\n",i);
	}
}
