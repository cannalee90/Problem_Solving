#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	priority_queue<ll, vector<ll>, less<ll> > p_pq;
	priority_queue<ll, vector<ll>, greater<ll> > n_pq;
	scanf("%lld", &n);
	bool isZero = false;
	for (ll i = 0; i < n; i++){
		ll temp;
		scanf("%lld", &temp);
		if (temp > 0)
			p_pq.push(temp);
		else if(temp < 0)
			n_pq.push(temp);
		if (temp == 0) isZero = true;
	}
	ll ans = 0;
	while (p_pq.size() > 1){
		ll t1 = p_pq.top(); p_pq.pop();
		ll t2 = p_pq.top(); p_pq.pop();
		if (t1 * t2 < t1 + t2) ans += (t1 + t2);
		else ans += t1 * t2;
	}
	if (p_pq.size() == 1) ans += p_pq.top();
	while (n_pq.size() > 1){
		ll t1 = n_pq.top(); n_pq.pop();
		ll t2 = n_pq.top(); n_pq.pop();
		ans += t1 * t2;
	}
	if (!isZero && n_pq.size() == 1) ans += n_pq.top();
	cout << ans << endl;
}