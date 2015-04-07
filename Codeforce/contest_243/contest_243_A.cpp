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
	ll n, m;
	ll mmax = -1;
	ll sum = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		ll t1;
		cin >> t1;
		sum += t1;
		mmax = max(mmax, t1);
	}
	if (sum - mmax > m)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}