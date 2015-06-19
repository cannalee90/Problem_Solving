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
int cnt = 0;
ll DP[40][40];

ll sol(int full, int half){
	ll &ret = DP[full][half];
	if (full == 0 && half == 0) {
		cnt++; return 1;
	}
	if (ret != 0) return ret;
	if (full != 0) ret += 	sol(full - 1, half + 1);
	if (half != 0) ret += sol(full, half - 1);
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	while (cin >> n){
		if (n == 0) break;
		else 
			cout << sol(n, 0) << endl;
	}
}