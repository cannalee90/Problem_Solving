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

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ans = 1;
	scanf("%d", &n);
	vector<int> vi(n), dp(n + 1);
	for (int i = 0; i < n; i++) scanf("%d", &vi[i]);
	dp[vi[0]] = 1;
	for (int i = 1; i < n; i++){
		dp[vi[i]] = dp[vi[i] - 1] + 1;
		ans = max(dp[vi[i]], ans);
	}
	cout << n - ans << endl;
}