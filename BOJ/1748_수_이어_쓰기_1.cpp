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
	ll n;
	ll total = 0;
	ll loop = 1;
	cin >> n;
	while(n)
	{
		if( n > (9 * pow(10, (double)loop- 1)))
		{
			total += loop * 9 * pow(10, (double)loop - 1);
			n -= 9 * pow(10, (double)loop - 1);
		}
		else
		{
			total += loop * n;
			break;
		}
		loop++;
	}
	cout << total << endl;
}
