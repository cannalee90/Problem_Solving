#include <iostream>
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

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll k = 0, n = 0, p = 0;
	int ans = 0;
	cin >> k >> n >> p;
	for (int i = 1; i <= p; i++){
		ans += i * k;
	}
	if (ans > n) cout << ans - n << endl;
	else cout << "0" << endl;
}