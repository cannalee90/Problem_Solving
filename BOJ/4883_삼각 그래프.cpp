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

int mmove[4][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 } };

ll get_min(int i, int j, vector<vector<ll> > &DP){
	ll mmin = INT_MAX;
	for (int k = 0; k < 4; k++)
		mmin = min(mmin, DP[i + mmove[k][0]][j + mmove[k][1]]);
	return mmin;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int test_num = 1;
	while (~scanf("%d", &n)){
		if (n == 0)
			return 0;
		vector<vector<ll> > data(n + 1, vector<ll>(5, 0));
		vector<vector<ll> > DP(n + 1, vector<ll>(5, INT_MAX));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				scanf("%lld", &data[i][j]);
			}
		}
		DP[1][2] = data[1][2];
		DP[1][3] = data[1][3] + data[1][2];
		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				DP[i][j] = data[i][j] + get_min(i, j, DP);
			}
		}
		printf("%d. %d\n", test_num++, DP[n][2]);
	}
}