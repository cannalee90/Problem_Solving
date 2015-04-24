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
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n;
		vector<int>coin(n);
		for (int i = 0; i < n; i++)
			cin >> coin[i];
		cin >> m;
		vector<int> DP(m + 1, 0);
		DP[0] = 1;
		for (int i = 0; i < n; i++){
			int cur = coin[i];
			for (int j = cur; j <= m; j++)
				DP[j] += DP[j - cur];
		}
		cout << DP[m] << endl;
	}
}