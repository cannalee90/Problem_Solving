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
	vector<ll> DP;
	ll n;
	cin >> n;
	DP = vector<ll>(n + 1, 0);
	DP[1] = 1;
	for (int i = 2; i <= n; i++){
		int cnt = 0;
		for (int j = 1; j <= sqrt(i); j++){
			if (i % j == 0)
				cnt++;
		}
		DP[i] = DP[i - 1] + cnt;
	}
	cout << DP[n] << endl;
}