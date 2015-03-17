#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 10000007
#define INF 10000009
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
		int n, m;
		cin >> n >> m;
		vector<vector<int > > coupon(n);
		vector<int> couponList(m + 1);
		vector<int> price;
		for(int i = 0; i<n; i++)
		{
			int couponNumber, t1;
			cin >> couponNumber;
			for(int j = 0; j<couponNumber; j++)
			{
				cin >> t1;
				coupon[i].push_back(t1);
			}
			cin >> t1;
			price.push_back(t1);
		}
		for(int i = 0; i<m; i++)
		{
			cin >> couponList[i + 1];
		}
		long long ans = 0;
		for(int i = 0; i<n; i++)
		{
			int mmin = INF;
			int minp = -1;
			for(int j = 0; j<coupon[i].size(); j++)
			{
				mmin = min(mmin, couponList[coupon[i][j]]);
			}
			ans += mmin * price[i];
		}
		cout << ans << endl;
	}

}
