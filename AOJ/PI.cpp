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
#define INF 900000000


typedef long long ll;
using namespace std;


ll scoring(const string &data, int p)
{
	int d = 0;
	set<ll> temp;
	vector<ll> d2;
	for(int i = 0; i<p; i++)
	{
		temp.insert(data[i] - '0');
		d2.push_back(data[i] - '0');
	}
	if(temp.size() == 1) return 1;
	int differ = d2[1] - d2[0];
	d = 0;
	for(int i = 1; i<p; i++)
	{
		if(d2[i] - d2[i-1] == differ)
		{
			d++;
		}
	}
	if(d == p - 1 && abs(differ) == 1) return 2;
	int a = 0;
	for(int i = 0; i<p; i++)
	{
		if(i % 2 == 1 && d2[i] == d2[1])
		{
			a++;
		}
		else if(i % 2 == 0 && d2[i] == d2[0])
		{

			a++;
		}
	}
	if(a == p) return 4;
	if(d == p - 1 && abs(differ) != 1) return 5;
	return 10;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n, t;
	cin >> t;
	while(t--)
	{
		string t1,d1;
		cin >> t1;
		d1 = t1;
		n = t1.length();
		vector<ll> DP(n + 1, INF);
		DP[0] = 0;
		for(int j = 3; j<=n; j++)
		{
			for(int i = 3; i<=5 ;i++)
			{
				if(j - i>=0)
				{
					if(scoring(d1.substr(j - i, i), i) + DP[j - i] < DP[j])
					{
						DP[j] = scoring(d1.substr(j - i, i), i) + DP[j - i];
					}
				}
			}
		}
		cout << DP[n] << endl;
	}
}
