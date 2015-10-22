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

struct coor {
	int x, y;
	coor() {}
};
vector<coor> first_dis;
vector<coor> second_dis;
int dp[1001][1001]; //dp[i][j] = i는 첫번째 경찰차 j는 두번째 경찰차 각각의 위치에서 다음 사건을 해결하러 갈때의 최소값
vector<int> path; //역추적을 조심해서 해야 한다
int n;
int m;

int solve(int first, int second) {
	if (first == n || second == n) return 0;
	int &ret = dp[first][second];
	if (ret != -1) return ret;
	ret = INF;
	int next = max(first, second) + 1;
	int fi = solve(next, second) + abs(first_dis[first].x - first_dis[next].x) + abs(first_dis[first].y - first_dis[next].y);
	int se = solve(first , next) + abs(second_dis[second].x - second_dis[next].x) + abs(second_dis[second].y - second_dis[next].y);
	ret = min(fi, se);
	return ret;
}

void get_path(int first, int second) {
	if (first == n || second == n) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << endl;
		return;
	}
	
	int next = max(first, second) + 1;
	int fi = dp[next][second] + abs(first_dis[first].x - first_dis[next].x) + abs(first_dis[first].y - first_dis[next].y);
	int se = dp[first][next] + abs(second_dis[second].x - second_dis[next].x) + abs(second_dis[second].y - second_dis[next].y);
	if (fi < se) {
		path.push_back(1);
		get_path(next, second);
	} else {
		path.push_back(2);
		get_path(first, next);

	}
	return;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> m;
	cin >> n;
	first_dis.assign(n + 1, coor());
	second_dis.assign(n + 1, coor());

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> first_dis[i].x >> first_dis[i].y;
	}
	second_dis = first_dis;
	first_dis[0].x = first_dis[0].y = 1;
	second_dis[0].x = second_dis[0].y = m;
	cout << solve(0, 0) << endl;
	get_path(0, 0);
}
