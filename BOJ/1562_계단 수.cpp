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
ll dp[1 << 11][11][110];
ll visited[10];
int track[101];

ll sol(int length, int num, int status){
	if (num < 0 || num > 9) return 0;
	if (length == n){
		if (((1 << 10) - 1) == status) 
			return 1;
		else 	
			return 0;
	}
	ll &ret = dp[status][num][length];
	if (ret != -1) return ret;
	ret = sol(length + 1, num + 1, status | (1 << (num + 1))) + sol(length + 1, num - 1, status | (1 << (num - 1)));
	return ret % 1000000000;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll ans = 0;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 10; i++){
		ans += sol(1, i, (1 << i));
		ans %= 1000000000;
	}
	cout << ans << endl;
}