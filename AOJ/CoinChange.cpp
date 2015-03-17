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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	for(int p = 0; p <t; p++)
	{
		long long price[5100] = {0};
		int change;
		int c;
		int coin[100] = {0};
		cin >> change >> c;
		for(int i = 0; i<c; i++)
		{
			cin >> coin[i];
		}
		sort(coin, coin + c);
		for(int i = 0; i<c; i++)
		{
			price[coin[i]] ++;
			for(int j = coin[i]+1; j<=change; j++)
			{
				if(price[j - coin[i]] != 0)
					price[j] += price[j - coin[i]];
			}
		}
		cout << price[change] % 1000000007 << endl;
	}
}