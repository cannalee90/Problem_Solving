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

int LCM(int a, int b)
{
	if(a > b) swap(a, b);
	while(1)
	{
		if(a == 0)
			return b;
		else
		{
			int temp = a;
			a = b % a;
			b = temp;
		}
	}
}


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int cnt;
		int t1, t2;
		cin >> n >> m >> t1 >> t2;
		if(n > m)
		{
			swap(n,m);
			swap(t1, t2);
		}
		int x = t1, y = t1;
		cnt = t1;
		int d = 0;
		int L = LCM(n,m);
		while(cnt <= (n * m) / L)
		{
			if(y == t2)
			{
				d = 1;
				break;
			}
			cnt += n;
			y += n;
			if(y > m)
				y -= m;
		}
		if(d == 1)
			cout << cnt << endl;
		else 
			cout << "-1" << endl;
	}
}
