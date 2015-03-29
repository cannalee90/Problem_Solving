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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	cin >> n;
	vector<vector<ll> > DP(n * 2 , vector<ll>(n * 2, 0));
	vector<vector<ll> > table(n * 2, vector<ll>(n * 2, 0));

	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			cin >> table[i][j];
		}
	}

	DP[0][0] = 1;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			if (table[i][j] == 0)
				continue;
			ll jumping = table[i][j];
			DP[i + jumping][j] += DP[i][j];
			DP[i][j + jumping] += DP[i][j];


		}
	}
	cout << DP[n - 1][n - 1] << endl;
}