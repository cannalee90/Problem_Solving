#include <iostream>
#include <utility>
#include <limits.h>
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
	vector<int> DP(n + 1);
	DP[1] = 5;
	for (int i = 2; i <= n; i++){
		DP[i] = DP[i - 1] + ((i + 1) * 3 - 2);
		DP[i] %= 45678;
	}
	cout << DP[n] << endl;
}