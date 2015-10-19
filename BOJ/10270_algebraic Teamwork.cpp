#include <iostream>
#include <climits>
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

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll ans = 1;
		for (int i = 1; i <= n; i++)
			ans = (ans * i) % 1000000007LL;
		cout << ans - 1LL<< endl;
	}
}