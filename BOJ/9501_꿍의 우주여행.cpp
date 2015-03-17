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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n, m;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		double velocity, fuel, consume;
		int ans = 0;
		for(int i = 0; i<n; i++)
		{
			cin >> velocity >> fuel >> consume;
			if(velocity * fuel / consume >= m) ans++;
		}
		cout << ans << endl;
	}
}
