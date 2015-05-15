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

int n, m, t;
int mmove[8][2] = { { -2, 1 }, //
					{ -1, 2 }, //
					{ 1, 2 }, //
					{ 2, 1 }, //
					{ 2, -1 }, //
					{ 1, -2 }, //
					{ -1, -2 }, //
					{ -2, -1 } };//

inline bool isPossible(int h, int w){
	if (h < 0 || w < 0 || h >= n || w >= n) return false;
	return true;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	scanf("%d", &t);
	while (t--){
		int beginH, beginW, endH, endW;
		scanf("%d", &n);
		scanf("%d %d", &beginH, &beginW);
		scanf("%d %d", &endH, &endW);

		if (beginH == endH && beginW == endW){
			cout << 0 << endl;
			continue;
		}

		vector<vector<int > > board(n, vector<int>(n, INT_MAX));
		board[beginH][beginW] = 0;
		queue <pair<int, int > > que;
		que.push(make_pair(beginH, beginW));

		while (!que.empty()){
			int hereH = que.front().first, hereW = que.front().second;
			que.pop();
			for (int i = 0; i < 8; i++){
				int thereH = hereH + mmove[i][0];
				int thereW = hereW + mmove[i][1];
				if (isPossible(thereH, thereW)){
					if (board[thereH][thereW] > board[hereH][hereW] + 1){
						board[thereH][thereW] = board[hereH][hereW] + 1;
						que.push(make_pair(thereH, thereW));
					}
				}
			}
		}
		printf("%d\n", board[endH][endW]);
	}
}
