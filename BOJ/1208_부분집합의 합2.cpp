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

ll n, m, test;
ll limit;
ll t;
vector<ll> vi, vii;
vector<ll> sa;
vector<ll> sb;

void ssum(ll length, ll sum, vector<ll> &vi, vector<ll> &sa){
	if (length == vi.size()){
		sa.push_back(sum);
		return;
	}
	ssum(length + 1, vi[length] + sum, vi, sa);
	ssum(length + 1, sum, vi, sa);
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll ans = 0;
	cin >> n >> m;
	vi = vector<ll>(n / 2);
	vii = vector<ll>(n - n /2);
	for (ll i = 0; i < n / 2; i++){
		cin >> vi[i];
	}
	for (ll i = 0; i < n - n / 2; i++) {
		cin >> vii[i];
	}
	ssum(0, 0, vi, sa);
	
	ssum(0, 0, vii, sb);
	sort(sb.begin(), sb.end());
	vector<ll>::iterator litor, uitor;
	for (ll i = 0; i < sa.size(); i++){
		litor = lower_bound(sb.begin(), sb.end(), m - sa[i]);
		uitor = upper_bound(sb.begin(), sb.end(), m - sa[i]);
		ans += (uitor - litor);
	}
	if(m == 0) cout << ans - 1 << endl;
	else cout << ans << endl;
}