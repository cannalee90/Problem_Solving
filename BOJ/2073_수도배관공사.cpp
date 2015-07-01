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

using namespace std;
int dp[5][100001];


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int> > pipe(m);
	for (int i = 0; i < m; i++){
		scanf("%d %d", &pipe[i].first, &pipe[i].second);
	}
//	sort(pipe.begin(), pipe.end());
	dp[0][0] = INT_MAX;
	int here, prev;
	for (int i = 1; i <= m; i++){
		int cur = pipe[i - 1].first;
		int flow = pipe[i - 1].second;
		prev = ((i - 1) % 2);
		here = i % 2;
		for (int j = 0; j < cur; j++)
			dp[here][j] = dp[prev][j];
		for (int j = cur; j <= n; j++){
			int a = dp[prev][j];
			dp[here][j] = max(a, min(dp[prev][j - cur], flow));
		}
	}
	if (dp[m % 2][n] == 0) while (1){}
	cout << dp[m%2][n] << endl;
}