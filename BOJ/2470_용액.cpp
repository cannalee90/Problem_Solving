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

const long long INF = 999999999999;
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	vector<long long> data;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		ll t1;
		cin >> t1;
		data.push_back(t1);
	}
	sort(data.begin(), data.end());

	int up_bd = data.size() - 1;
	long long ans = INF, minp = -1;
	long long ans_1, ans_2;

	for(int i = 0; i<=up_bd; i++)
	{
		long long  m = data[i];
		long long t2 = abs(m + data[up_bd]);
		for(int j = up_bd - 1; j> i; j--)
		{
			if(t2 > abs(m + data[j]))
			{
				t2 = abs(m + data[j]);
			}
			else break;
		}
		if(ans > abs(t2))
		{
			ans = t2;
		}

	}
	cout << ans << endl;
}	