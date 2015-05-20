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

int n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n = 1;
	cin >> t;
	while (t--){
		vector<ll> side(3);
		cin >> side[0] >> side[1] >> side[2];
		sort(side.begin(), side.end());
		ll c = side[2] * side[2];
		ll a = side[0] * side[0];
		ll b = side[1] * side[1];
		if (c - a - b == 0)
			printf("Scenario #%d:\nyes\n", n++);
		else
			printf("Scenario #%d:\nno\n", n++);
		cout << "\n";
	}
}