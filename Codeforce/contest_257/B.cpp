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
	ll x, y;
	ll n;
	vector<ll> result(7);
	cin >> x >> y >> n;
	result[1] = x;
	result[2] = y;
	for (int i = 3; i <= 6; i++)
		result[i] = (result[i - 1] - result[i - 2]) % 1000000007;
	n %= 6;
	if (n == 0) n = 6;
	if (result[n] < 0)
		cout << result[n] + 1000000007 << endl;
	else
		cout << result[n] << endl;
}