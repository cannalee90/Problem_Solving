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
	ll a, b;
	while (cin >> a >> b){
		if (a == 0 && b == 0) return 0;
		ll ans = 0;
		if (b > a) swap(a, b);
		bool WasCarried = false;
		while (a || b){
			bool isCarry = ((a % 10) + (b % 10) + WasCarried) / 10;
			if (isCarry){
				ans++;
				WasCarried = true;
			}
			else
				WasCarried = false;
			a /= (ll)10;
			b /= (ll)10;
		}
		cout << ans << endl;
	}
}