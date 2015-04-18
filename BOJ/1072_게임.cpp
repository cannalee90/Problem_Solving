#include <iostream>
#include <climits>
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

bool isPossible(const ll &time, const ll &z, const ll &x, const ll &y){

	double temp = ((y + time)  * 100) / (time + x);
	if (temp > z)

		return true;
	else
		return false;
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll x, y, z;
	int t;
	cin >> t;
	for(int i = 0; i<t; i++){
		cin >> x >> y;
		ll ans = INT_MAX;
		z = (y * 100  / x);
		if (z >=  99){
			cout << "-1" << endl;
			continue;
		}


		ll left = 1, right = INT_MAX;
		while (left <= right){
			ll time = (left + right) / 2;
			if (isPossible(time, z, x, y)){
				right = time - 1;
				ans = min(time, ans);
			}
			else
				left = time + 1;
		}
		if (ans != INT_MAX)
			cout << ans << endl;
		else
			cout << "-1" << endl;
	}
}

