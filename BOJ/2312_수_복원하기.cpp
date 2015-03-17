#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

#define INF
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;

const int M = 100 * 100;

bool P[M + 1];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	vector<int> Prime;
	for(int i = 2; i<=M; i++)
	{
		if(!P[i])
		{
			Prime.push_back(i);
			for(int j = i; j<=M; j+=i)
			{
				P[j] = 1;
			}
		}
	}
	while(t--)
	{
		ll n;
		cin >> n;
		for(int i = 0; i<Prime.size(); i++)
		{
			if(n % Prime[i] == 0)
			{
				int cnt = 0;
				while(n % Prime[i] == 0)
				{
					n /= Prime[i];
					cnt++;
				}
				cout << Prime[i] << " " << cnt << endl;
			}
		}
		if(n != 1)
		{
			cout << n << " " << "1" << endl;
		}
	}
}