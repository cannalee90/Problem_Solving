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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	ll sum = 0;
	cin >> n;
	vector<ll> data(n + 1);
	vector<ll> partial_1(n + 1);
	vector<ll> partial_2(n + 1);
	for (int i = 1; i <= n; i++){
		ll t1;
		cin >> t1;
		data[i] = t1;
		sum += t1;
		partial_1[i] = sum;
	}
	sort(data.begin() + 1, data.end());
	sum = 0;
	for (int i = 1; i <= n; i++){
		sum += data[i];
		partial_2[i] = sum;
	}
	cin >> m;
	while (m--){
		int q;
		cin >> q;
		if (q == 2){
			int l, r;
			cin >> l >> r;
			cout << partial_2[r] - partial_2[l - 1] << endl;
		}
		if (q == 1){
			int l, r;
			cin >> l >> r;
			cout << partial_1[r] - partial_1[l - 1]<< endl;
		}
	}
}