#include <iostream>
#include <limits.h>
#include <utility>
#include <functional>
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

int n, limit, p;

ll process(vector<pair<ll, ll> > data){
	ll ans = 0;
	ll bus = limit;
	bool full = false;
	for (ll i = 0; i < data.size();){

		ll &here_dis = data[i].first;
		ll &here_stu = data[i].second;

		if (bus == 0)
			bus = limit;

		if (here_stu == 0){
			i++;
			continue;
		}
		if (here_stu > bus){
			if (bus == limit){
				ans += (ll)2 * (ll)here_dis * ((ll)here_stu / (ll)limit);
				here_stu %= limit;
			}
			else{
				here_stu -= bus;
				bus = 0;
			}
		}
		else if (here_stu <= bus){
			if (bus == limit)
				ans += (ll)2 * (ll)here_dis;
			bus -= here_stu;
			here_stu = 0;
		}
	}
	return ans;
}

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b){
	return a.first > b.first;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);

#endif
	vector<pair<ll, ll> > data_1;
	vector<pair<ll, ll> > data_2;

	scanf("%d %d %d", &n, &limit, &p);

	for (ll i = 0; i < n; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 < p)
			data_1.push_back(make_pair(p - t1, t2));
		else
			data_2.push_back(make_pair(t1 - p, t2));
	}
	sort(data_1.begin(), data_1.end(), cmp);
	sort(data_2.begin(), data_2.end(), cmp);

	ll ans = 0;
	ans += process(data_1);
	ans += process(data_2);
	cout << ans << endl;
}