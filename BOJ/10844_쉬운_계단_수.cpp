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

ll dp[101][101];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; j++){
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= 9; i++) ans = (ans + dp[n][i]) % 1000000000;
	cout << ans << endl;
}