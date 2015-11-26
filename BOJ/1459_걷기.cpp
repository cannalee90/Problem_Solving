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

#define INF 987654321


int main(){
	freopen("input.txt", "r", stdin);
	ll x, y, w, s, q, p;
	cin >> x >> y >> w >> s;
	if (w * 2LL < s) {
		q = w;
		cout << x * q + y * q <<endl;
	}
	else if (w >= s){
		ll a = (((max(x, y) - min(x, y)) / 2) * 2);
		ll b = (max(x, y) - min(x, y)) % 2LL;
		cout << (min(x, y) * s) + (a * s) + (b * w) << endl;
	}
	else {
		cout << (min(x, y) * s) + (max(x, y) - min(x, y)) * w << endl;
	}
}
