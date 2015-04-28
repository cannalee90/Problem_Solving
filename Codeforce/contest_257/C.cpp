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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n, m, k;
	cin >> n >> m >> k;
	if (k > n + m - 2) {
		cout << "-1" << endl;
		return 0;
	}
	ll h, w;
	ll q = k;
	if (n - 1 > k)
		h = (n / (k + 1)) * m;
	else
	{
		k -= (n - 1);
		h = 1 * (m / (k + 1));
	}
	if (m - 1 > q)
		w = (m / (q + 1)) * n;
	else
	{
		q -= (m - 1);
		w = 1 * (n / (q + 1));
	}
	cout << max(h, w) << endl;
}