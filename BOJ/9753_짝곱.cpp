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

bool P[100001];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n = 100000;
	vector<int> Prime;
	Prime.push_back(2);
	for(int i = 2; i<=n/2; i+=2) P[i] = 1;
	for(int i = 3; i<=n/2; i++)
	{
		if(!P[i])
		{
			Prime.push_back(i);
			for(int j = i; j<=n; j+=i)
			{
				P[j] = 1;
			}
		}
	}
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag  = 0;
		int mmin = INF;
		for(int i = 0; i<Prime.size(); i++)
		{
			for(int j = 0; j<Prime.size(); j++)
			{
				if(i == j) continue;
				if(Prime[i] * Prime[j] >= n)
				{
					mmin = min(mmin, Prime[i] * Prime[j]);
					break;
				}
			}
		}
		cout << mmin << endl;
	}
}
