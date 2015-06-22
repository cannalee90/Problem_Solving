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

int n, m, t, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> n >> m >> t){
		if (n == 0 && m == 0 && t == 0) break;
		int ans = ((t / m) * n);
		t %= m;
		(t / n == 0) ? ans += t % n : ans += n;
		printf("Case %d: %d\n", ++test, ans);
	}
}