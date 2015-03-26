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
	int n;
	cin >> n;
	vector<long long> DP(n + 1, 0);
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; i++){
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] %= 15746;
	}
	printf("%lld\n", DP[n]);
}