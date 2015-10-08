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

ll a, b;


ll seq(ll l){
	return a + (l - 1LL) * b;
}

ll part(ll first, ll last){
	return (seq(first) + seq(last)) * (first - last + 1LL) / 2LL;
}

bool isPossible(ll mid, ll m, ll t, ll left){
	if (seq(mid) > t) return false;
	if (part(mid,left) > t * m) return false;
	return true;
}



int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll q;
	cin >> a >> b >> q;
	for (int i = 0; i < q; i++){
		ll l, m, t;
		cin >> l >> t >> m;
		ll left = l, right = INT_MAX, ans = -1;
		if (seq(left) <= t){
			while (left <= right){
				ll mid = (left + right) / 2LL;
				if (isPossible(mid, m, t, l)){
					ans = mid;
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
			}
		}
		cout << ans << endl;
	}
}

