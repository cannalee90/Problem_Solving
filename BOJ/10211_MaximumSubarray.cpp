#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

typedef long long ll;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll t,n,t1,t2;
	ll m1 = -9999, m2 = 0;
	cin >> t;
	while(t--)
	{
		cin >> n;
		t2 = 0;
		m2 = 0;
		m1 = -9999;
		while(n--)
		{
			cin >> t1;
			if(m1 < t1) m1 = t1;

			if(t1 >= 0)
			{
				t2 += t1;
			}
			else
			{
				if(t2 + t1 < 0)
				{
					t2 = 0;
					continue;
				}
				else
				{
					t2 += t1;
				}
			}
			if(m2 < t2) m2 = t2;
		}
		if(m2)
		{
			cout << m2 << endl;
		}
		else
		{
			cout << m1 << endl;
		}
	}
}
