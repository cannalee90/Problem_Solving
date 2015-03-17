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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	scanf("%lld %lld", &n, &m);
	if(n > m)
		swap(n, m);
	if((m - n) - 1 <= 0) 
		cout << "0" << endl;
	else
	{
		cout << m - n - 1 << endl;
		for(ll i = n + 1; i<m-1; i++)
		{
			printf("%lld ", i);
		}
		printf("%lld\n", m-1);
	}
}
