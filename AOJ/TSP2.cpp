#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

double graph[15][15];
double dp[15][1 << 15];
int test, n, m;
double ans;

double tsp(int vertex, int visited){
	double &ret = dp[vertex][visited];

	if (visited == 0)
		return 0;

	if (ret != 0) return ret;
	double mmin = 987654321;
	for (int i = 0; i < n; i++){
		int bit = 1 << i;
		if (visited & bit){
			mmin = min(tsp(i, visited - bit) + graph[vertex][i], mmin);
		}
		ret = mmin;
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> test;
	while (test--){
		cin >> n;
		memset(graph, 0, sizeof(graph));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		ans = 987654321;
		for (int i = 0; i < n; i++){
			int visited = ((1 << n) - 1) - (1 << i);
			ans = min(ans, tsp(i, visited));

		}
		printf("%.10lf\n", ans);
	}
}