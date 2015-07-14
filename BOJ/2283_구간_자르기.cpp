#include <iostream>
#include <functional>
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

ll n, t;
ll partial[1000001];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n, k, idx = 0;
	ll limit = 0;
	scanf("%lld %lld", &n, &k);
	vector<pair<ll, ll > > vp(n);
	for (ll i = 0; i < n; i++){
		scanf("%lld %lld", &vp[i].first, &vp[i].second);
		limit = max(limit, vp[i].second);
	}

	sort(vp.begin(), vp.end());
	priority_queue<pair<ll, ll >,vector<pair<ll, ll> >,	greater<pair<ll, ll > > > pq;
	for (ll i = 0; i <= limit; i++){
		while (!pq.empty() && pq.top().first < i)
			pq.pop();
		if(i !=  0)	partial[i] = partial[i - 1] + pq.size();
		while (idx < n && vp[idx].first <= i){
			swap(vp[idx].first, vp[idx].second);
			pq.push(vp[idx]);
			idx++;
		}
	}
	ll begin = 0, end = 1;
	ll ssum = partial[end] - partial[begin];
	while (end < 1000001){
		if (ssum < k) end++;
		else if (ssum > k) begin++;
		ssum = partial[end] - partial[begin];
		if (ssum == k){
			cout << begin << " " << end << endl;
			return 0;
		}
	}
	cout << "0 0" << endl;
}