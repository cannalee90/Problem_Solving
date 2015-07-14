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

using namespace std;
typedef long long ll;

int n, st;
int graph[20][20];
int dp[16][1 << 16];

int sol(int vertex, int status){
	int &ret = dp[vertex][status];
	if (status == (1 << n) - 1) {
		return graph[vertex][st];
	}
	int mmin = INT_MAX;
	if (ret != -1) return ret;
	for (int i = 0; i < n; i++){		
		if (!(status & (1 << i)) && graph[vertex][i] != 98765321){
			mmin = min(sol(i, status | (1 << i)) + graph[vertex][i], mmin);
		}
	}
	ret = mmin;
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> graph[i][j];
			if (graph[i][j] == 0) graph[i][j] = 987654321;
		}
	}
	int ans = INT_MAX;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++){
		st = i;
		ans = min(ans, sol(i, 1 << i));
	}
	cout << ans << endl;
}