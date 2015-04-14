#include <iostream>
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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<ll> DP(n + 1, 0);
	DP[0] = 1;
	DP[1] = 3;
	for (int i = 2; i <= n; i++){
		DP[i] = (DP[i - 1] * 2 + DP[i - 2]) % 9901;
	}
	cout << DP[n] << endl;
}