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

int n, m;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string a, b;
	ll l1, l2;
	ll total = 0;
	cin >> a;
	cin >> b;
	l1 = a.length();
	l2 = b.length();
	for(int i = 0; i<l1; i++)
	{
		for(int j = 0; j<l2; j++)
		{
			total += ((int)a[i]-'0') * ((int)b[j] - '0');
		}
	}
	cout << total << endl;
}
