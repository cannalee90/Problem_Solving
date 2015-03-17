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
	string s = "";
	cin >> n;
	string e = to_string((ll)n);
	for(int i = 1; i<=n; i++)
	{
		s += to_string((ll)i);	
	}
	ll l = s.length(), l2 = e.length();
	int cnt =0;
	int a = 0;
	for(int i = 0; i<=l; i++)
	{
		if(s[i] == e[a])
		{
			a++;
			if(a == e.length())
			{
				cout << i - (e.length() - 2) << endl;
				break;
			}
		}
		else
		{
			a = 0;
		}
	}
}
