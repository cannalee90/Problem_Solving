#include <iostream>
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
		cin >> money >> num_coin;
		money = 10000 - money;

		int changes[10001];
		int coins[15];
		memset(changes, -1, sizeof(changes));
		memset(coins, 0, sizeof(coins));
		for (int i = 0; i < num_coin; i++){
			int t1;
			scanf("%d", &t1);
			coins[i] = t1;
		}
		sort(coins, coins + num_coin);
		changes[0] = 0;
		for (int i = 0; i < num_coin; i++){
			int cur_coin = coins[i];
			for (int j = cur_coin; j <= money; j++){
				
				if(changes[j] != -1)
					{
						if (changes[j] > changes[j - cur_coin] + 1 && changes[j - cur_coin] != -1){
							changes[j] = changes[j - cur_coin] + 1;
						}
					}
				else if (changes[j] ==-1)
				{
					if (changes[j - cur_coin] != -1){
						changes[j] = changes[j - cur_coin] + 1;
					}
				}

			}
		}
		if (changes[money] == -1){
			printf("%d\n", 0);
		}
		else{
			printf("%d\n", changes[money]);
		}
	}
}