#include <iostream>
#include<functional>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

long long n;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int money;
		int num_coin;
		int coins[15];

		cin >> money >> num_coin;
		money = 10000 - money;
		for (int i = 0; i < num_coin; i++){
			int t1;
			scanf("%d", &t1);
			coins[i] = t1;
		}
		sort(coins, coins + num_coin, greater<int>());
		int ans = 0;
		for (int i = 0; i < num_coin; i++){
			ans += money / coins[i];
			money %= coins[i];
		}
		if (!money)
			printf("%d\n", ans);
		else
			printf("0\n");
	}
}