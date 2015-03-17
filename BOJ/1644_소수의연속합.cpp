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
 
ll n, m;
ll prime;
bool era[4000100];
vector<int> Prime;

 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    ll total = 0;
    cin >> n;
    prime = 3;
	Prime.push_back(2);
	while(prime <= sqrt((double)n))
    {
        for(int i = prime*2; i<=n; i+=prime)
        {
            era[i] = 1;
        }
        for(int i = prime+1; i<=n; ++i)
        {
            if(i % 2 != 0&&era[i] == 0)
            {
                prime = i;
                break;
            }
        }
    }
    for(int i = 3; i<=n; ++i)
    {
        if(!era[i] && i % 2)
			Prime.push_back(i);
	}
	ll cnt = 0;
	for(int i = 0; i<Prime.size(); i++)
	{
		ll sum = 0;
		for(int j = i; j<Prime.size(); j++)
		{
			sum += Prime[j];
			if(sum == n)
			{
				cnt++;
				break;
			}
			if(sum > n)
				break;
		}
	}
	cout << cnt << endl;
}