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
	int max = sqrt((double)123456 * 2) + 1;
	vector<bool> check((123456 + 1) * 2, 0);
	vector<int> Prime;
	int index = 2;
	while(index < max)
	{
		Prime.push_back(index);
		int t1 = index;
		while(t1 <= 123456 * 2)
		{
			check[t1] = 1;
			t1 += index;
		}
		int d = 0;
		for(int i = index + 1; i<=max; i++)
		{
			if(check[i] == 0)
			{
				d = 1;
				index = i;
				break;
			}
		}
		if(d == 0) break;
	}
	for(int i = index; i<=123456 * 2; i++)
	{
		if(check[i] == 0) Prime.push_back(i);
	}
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		int cnt = 0;
        vector<int>::iterator l = lower_bound(Prime.begin(), Prime.end(), n + 1);
		vector<int>::iterator r = upper_bound(Prime.begin(), Prime.end(), n * 2);
		cout << distance(l, r) << "\n";
	}
}
