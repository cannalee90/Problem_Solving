#include <iostream>
#include <cstdlib>
#include <ctime>
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

typedef long long ll;
using namespace std;

int n, m, test;
ll dp[11][2001];

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	for (int i = 1; i <= 2000; i++) dp[1][i] = i;
	for (int i = 2; i <= 10; i++){
		for (int j = 1; j <= 2000; j++){
			dp[i][j] += dp[i - 1][j / 2] + dp[i][j - 1];
		}
	}
	while (test--){
		scanf("%d %d", &n, &m);
		printf("%lld\n", dp[n][m]);
	}
}