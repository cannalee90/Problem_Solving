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
	int ans = 0;
	int DP[1001] = {};
	int data[1001] = {};
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> data[i];
	for (int i = 1; i <= n; i++){
		int mmax = 0;
		for (int j = i - 1; j >= 1; j--){
			if (data[j] < data[i] && mmax < DP[j])
				mmax = DP[j];
		}
		DP[i] = mmax + 1;
		ans = max(ans, DP[i]);
	}
	cout << ans  << endl;
}