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

int n, t, m;
char ans[30][30] = {};
int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

bool isPossible(int h, int w){
	if (h < 1 || w < 1 || h > n || w > m) return false;
	if (ans[h][w] == '0' || ans[h][w] == '1') return false;
	return true;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while (t--){
		int idx = 0, bit = 16, h = 1, w = 1;
		bool isEnd = false;
		cin >> n >> m;
		getchar();
		int num;
		char c = getchar();
		if (c == '\n') { num = 0, isEnd = true; }
		else if (c == ' ') num = 0;
		else num = c - 'A' + 1;

		int total = n * m, pre = 0;
		memset(ans, 0, sizeof(ans));
		while (total--){
			if (num & bit)
				ans[h][w] = '1';
			else
				ans[h][w] = '0';
			bit >>= 1;
			if (bit == 0){
				bit = 16;
				if (!isEnd){
					char c = getchar();
					if (c == '\n') { num = 0, isEnd = true; }
					else if (c == ' ') num = 0;
					else num = c - 'A' + 1;
				}
				else
					num = 0;
			}
			for (int i = 0; i < 4; i++){
				pre = (pre + i) % 4;
				if (isPossible(h + mmove[pre][0], w + mmove[pre][1])){
					h += mmove[pre][0];
					w += mmove[pre][1];
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				printf("%c", ans[i][j]);
			}
		}
		printf("\n");
	}
}
