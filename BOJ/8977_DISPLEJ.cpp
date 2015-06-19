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

int n, m, test, k, b;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> k >> b;
	ll total = 0, ans = 0;
	vector<ll> vi(n);
	vector<ll> par_sum(n);
	for (int i = 0; i < n; i++){
		cin >> vi[i];
		total += vi[i];
	}
	b %= n;
	ans = (k / n) * total;
	k %= n;
	b--;
	if (b == -1) b = n - 1;
	for (int i = 0; i < k; i++)
		ans += vi[(b + i) % n];
	cout << ans << endl;
}