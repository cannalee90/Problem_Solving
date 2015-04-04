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

ll get_record(int size, vector<ll> &track_length){
	int ret = 1;
	int temp = 0;
	for (int i = 0; i < track_length.size(); i++){
		temp += track_length[i];
		if (temp > size){
			temp = track_length[i];
			ret++;
		}
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n, m;
	ll sum = 0;
	ll ans = INT_MAX;
	scanf("%lld %lld", &n, &m);
	vector<ll> track_length(n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &track_length[i]);
		sum += track_length[i];
	}
	ll left = 1, right = sum;
	while (left <= right){
		ll size = (left + right) / 2;
		ll num_records = get_record(size, track_length);

		if (num_records > m){
			left = size + 1;
		}
		if (num_records <= m){
			right = size - 1;
			ans = min(size, ans);
		}
	}
	cout << ans << endl;
}