	#include <iostream>
	#include <limits.h>
	#include <utility>
	#include <fstream>
	#include <string>
	#include <string.h>
	#include <functional>
	#include <queue>
	#include <stdio.h>
	#include <algorithm>
	#include <set>
	#include <map>
	#include <vector>
	#include <stack>

	typedef long long ll;

	using namespace std;

	ll get_budget(ll cur_budget, vector<ll> &budget){
		ll total = 0;
		for (int i = 0; i < budget.size(); i++){
			if (cur_budget >= budget[i])
				total += budget[i];
			else
				total += cur_budget;
		}
		return total;
	}

	int main(){
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		ll n;
		ll limit;
		ll ans = INT_MIN;
		ll sum = 0;
		scanf("%lld", &n);
		vector<ll> budget(n);

		for (int i = 0; i < n; i++){
			scanf("%lld", &budget[i]);
			sum += budget[i];
		}
		scanf("%lld", &limit);
		sort(budget.begin(), budget.end());
		long long left = 1, right;
		right = budget[n - 1];
		while (left <= right){
			ll cur_budget = (left + right) / 2;
			ll total_budget = get_budget(cur_budget, budget);
			if (total_budget > limit){
				right = cur_budget - 1;
			}else {
				ans = max(ans, cur_budget);
				left = cur_budget + 1;
			}
		}
		cout << ans << endl;
	}