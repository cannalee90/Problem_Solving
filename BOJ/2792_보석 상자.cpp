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

ll n, m;

bool isPossible(ll mid, const vector<ll> &jewerly){
	ll cnt = 0;
	for (int i = 0; i < jewerly.size(); i++){
		ll cur = jewerly[i];
		cnt += cur / mid;
		if (cur % mid)
			cnt++;
	}
//	printf("mid : %lld \t cnt : %lld\n", mid, cnt);
	if (cnt > n)
		return false;
	else
		return true;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll left = 1, right = 0;
	ll ans = 0;
	vector<ll> jewerly;
	scanf("%lld %lld", &n, &m);
	jewerly = vector<ll>(m);
	for (int i = 0; i < m; i++){
		cin >> jewerly[i];
		right = max(right, jewerly[i]);
	}
	while (left <= right){
		ll mid = (left + right) / 2;
		if (isPossible(mid, jewerly)){
			right = mid - 1;
			ans = mid;
		}
		else
			left = mid + 1;
	}
	cout << ans << endl;
}