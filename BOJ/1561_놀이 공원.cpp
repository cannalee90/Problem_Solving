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

ll get_cus(vector<ll> &ride, ll time){
	ll total_cus = 0;
	for (int i = 0; i < ride.size(); i++)
		total_cus += time / ride[i];
	return total_cus;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n, m;
	ll mmax = LONG_MIN;
	ll mmax_cus;
	scanf("%lld %lld", &n, &m);
	vector<ll> ride(m);
	for (int i = 0; i < m; i++)
		scanf("%lld", &ride[i]);
	ll left = 0, right = 200000000000;
	ll num_cus;
	if (n - m <= 0){
		cout << n << endl;
		return 0;
	}
	while (left <= right){
		ll time = (left + right) / 2;
		num_cus = get_cus(ride, time);
		if (num_cus >= n - m){
			right = time - 1;
		}
		else{
			left = time + 1;
			if (time > mmax){
				mmax = time;
				mmax_cus = num_cus;
			}
		}
	}
	for (int i = 0; i < ride.size(); i++){
		if (mmax % ride[i] == ride[i] - 1)
			mmax_cus++;
		if (mmax_cus == n - m){
			cout << i + 1 << endl;
			return 0;
		}
	}
}