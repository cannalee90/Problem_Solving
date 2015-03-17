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
	ll n, k;
	while(cin >> n >> k)
	{
		ll p = n;
		while(p >= k)
		{
			n += p / k;
			p = p / k + (p % k);
		}
		cout << n << endl;
	}
}
