#include <iostream>
#include <limits.h>
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

ll squre_and_multiply(ll base, ll exp, ll mod){
	ll ans = 1;
	ll b = base;
	while (exp){
		if (exp & 1) 
			ans *= b;
		exp = exp >> 1;
		b *= b;
		b %= mod;
		ans %= mod;
	}
	return ans;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long long a, b, c;
	cin >> a >> b >> c;
	cout << squre_and_multiply(a, b, c) << endl;
}