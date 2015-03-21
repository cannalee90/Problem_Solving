#include <iostream>
#include <functional>
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

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	cin >> n;
	vector<ll> DP(n + 1, 0);
	vector<ll> numbers;
	int idx = 1;
	while (n >= idx){
		numbers.push_back(idx);
		idx *= 2;
	}

	DP[0] = 1;
	for (int i = 0; i < numbers.size(); i++){
		for (int j = numbers[i]; j <= n; j++){
			DP[j] += DP[j - numbers[i]];
			DP[j] %= 1000000000;
		}
	}
	cout << DP[n] << endl;
}