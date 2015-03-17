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
	ll n,m;
	int a[3] = {3,5};
	
	cin >> n;

	vector<ll> table(n + 1, INF);
	table[0] = 0;


	for(int i = 0; i<2; i++)
	{
		for(int j = a[i]; j<= n; j++)
		{
			if(table[j] > table[j - a[i]] +  1)
			{
				table[j] = table[j - a[i]] + 1;
			}
		}
	}
	if(table[n] != INF)
		cout << table[n] << endl;
	else 
		cout << "-1" << endl;
}
