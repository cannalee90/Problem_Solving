#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
	ll n;
	ll num = 1;
	ll cnt = 1;
	ll ans = 0;
	ll p = 1;
	cin >> n;
	while (n >= num * 9){
		ans = ans +  (ll)p * (ll)9 * (ll)cnt;
		n -= num * 9;
		cnt++;
		num *= 10;
		p *= 10;
	}
	cout << (ans + (n)* (cnt)) % 1234567 << endl;
}