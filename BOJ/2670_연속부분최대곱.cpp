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
	long double mmax;
	cin >> n;
	vector<long double> DP(n + 1);
	long double cur;
	cin >> cur;
	DP[0] = cur;
	mmax = cur;
	for (int i = 1; i < n; i++){
		cin >> cur;
		if (cur > DP[i - 1] * cur)
			DP[i] = cur;
		else
			DP[i] = DP[i - 1] * cur;
		mmax = max(mmax, DP[i]);
	}
	printf("%.3lf\n", mmax);
}