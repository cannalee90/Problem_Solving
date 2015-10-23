#include <iostream>
#include <climits>
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

typedef long long ll;
using namespace std;

#define INF 987654321
int n, m;
int ans = 0;
struct coor {
	int x;
	int y;
};
vector<coor> data;
double dp[600][600];	//정점이 L-R인지 R-L패스에 속하는지를 결정하면 된다.
						//경찰차 문제와 같이 2차원 DP를 돌리면 된다.
double dis(int u, int v) {
	return sqrt((double)abs(data[u].x - data[v].x) * (double)abs(data[u].x - data[v].x) + (double)abs(data[u].y - data[v].y) * (double)abs(data[u].y - data[v].y));
}

double solve(int up, int down){
	double &ret = dp[up][down];
	if (ret != -1) return ret;
	int here = max(up, down);
	if (here == n - 2) 
		return dis(min(up, down), n - 1) + dis(max(up, down), n - 1);
	ret = INF;
	ret = min(ret, solve(here + 1, down) + dis(here + 1, up));
	ret = min(ret, solve(up, here + 1) + dis(here + 1, down));

	return ret;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = -1;
		data.assign(n, coor());
		for (int i = 0; i < n; i++)
			cin >> data[i].x >> data[i].y;
		printf("%.10lf\n", solve(0, 0));
	}
}
