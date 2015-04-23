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

ll n, m, k;

bool isPossible(int dis, const vector<ll> &location){
	int cnt = 1;
	int here = location[0];
	for (int i = 1; i < location.size(); i++){
		ll cur = location[i];
		if (here + dis <= cur){
			here = cur;
			cnt++;
		}
	}
	if (cnt >= m)
		return true;
	else
		return false;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll ans = -1;
	cin >> n >> m >> k;
	vector<ll> location(k);
	for (int i = 0; i < k; i++)
		cin >> location[i];
	ll left = 0, right = n;
	while (left <= right){
		int dis = (left + right) / 2;
		if (isPossible(dis, location)){
			ans = dis;
			left = dis + 1;
		}else
			right = dis - 1;
	}
	cout << "1";
	int here = location[0];
	int cnt = 1;
	for (int i = 1; i < location.size(); i++){
		ll cur = location[i];
		if (here + ans <= cur && cnt < m){
			cout << "1";
			here = cur;
			cnt++;
		}
		else
			cout << "0";
	}
	cout << endl;
}