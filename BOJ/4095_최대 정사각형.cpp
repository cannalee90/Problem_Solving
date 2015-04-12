#include <iostream>
#include <limits.h>
#include <climits>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
	int n, m;
	while (1){
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		vector<vector<int> > data(n + 1, vector<int>(m + 1, 0));
		vector<vector<int> > DP(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &data[i][j]);
		int mmax = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (data[i][j] == 1){
					DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
					mmax = max(DP[i][j], mmax);
				}
			}
		}
		printf("%d\n", mmax);
	}
}