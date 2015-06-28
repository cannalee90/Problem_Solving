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

ll dp[4][50001], arr[50001];

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> m;
	for (int i = 1; i <= 3; i++){
		for (int j = i * m; j <= n; j++){
			dp[i][j] = (arr[j] - arr[j - m]) + dp[i - 1][j - m];
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
		}
	}
	cout << dp[3][n] << endl;
}