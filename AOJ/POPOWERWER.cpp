#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

#define hashvalue_1 10000007
#define hashvalue_2 10000009
#define INF 900000000


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		set<pair<ll, ll> > hashtable;
		cin >> a >> b;
		for(int i = 1; i<=a; i++)
		{
			int key_1 = 1;
			int key_2 = 1;
			for(int j = 1; j<=b; j++)
			{
				key_1 *= i;
				key_2 *= i;
				key_1 = key_1 % hashvalue_1;
				key_2 = key_2 % hashvalue_2;
				hashtable.insert(make_pair(key_1, key_2));
			}
		}
		cout << hashtable.size() << endl;
	}
}
