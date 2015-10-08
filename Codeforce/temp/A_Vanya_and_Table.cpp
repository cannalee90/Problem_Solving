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

using namespace std;
typedef long long ll;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ans += (ll)(c - a + 1) * (ll)(d - b + 1);
	}
	cout << ans << endl;
}