#include <iostream>
#include <utility>
#include <limits.h>
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

typedef long long ll;
using namespace std;

inline ll get_watt(ll cost){
	ll watt = 0;
	if (cost >= 200){
		watt += 100;
		cost -= 200;
	}
	else {
		watt += cost / 2;
		cost = 0;
	}
	if (cost >= 29700){
		watt += 9900;
		cost -= 29700;
	}
	else {
		watt += cost / 3;
		cost = 0;
	}
	if (cost >= 990000 * 5){
		watt += 990000;
		cost -= 990000 * 5;
	}
	else{
		watt += cost / 5;
		cost = 0;
	}
	watt += (cost / 7);
	return watt;
}
inline ll get_cost(ll watt){
	ll cost = 0;

	if (watt > 1000000){
		cost += (watt - 1000000) * 7;
		watt -= (watt - 1000000);
	}
	if (watt > 10000){
		cost += (watt - 10000) * 5;
		watt -= (watt - 10000);
	}
	if (watt > 100){
		cost += (watt - 100) * 3;
		watt -= (watt - 100);
	}
	cost += (watt) * 2;
	return cost;
}



int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll total, differ;
	while (cin >> total >> differ){
		if (total == differ && total == 0) return 0;
		ll left = 0;
		ll right = get_watt(total) / 2;
		ll t = get_watt(total);
		ll d = get_watt(differ);
		while (left <= right){
			ll sangeon = (left + right) / 2;
			ll another = t - sangeon;
			if (get_cost(another) - get_cost(sangeon) == differ){
				cout << get_cost(sangeon) << endl;
				break;
			}
			if (differ > get_cost(another) - get_cost(sangeon))
			{
				right = sangeon - 1;
			}
			else{
				left = sangeon + 1;
			}
		}
	}
}