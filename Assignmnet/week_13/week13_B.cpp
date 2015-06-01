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
int n, t, m, d;
char board[410][410];

int mmove[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int counting(int h, int w){
	int cnt = 0;
	for (int i = 0; i < 4; i++){
		int next_h = mmove[i][0] + h;
		int next_w = mmove[i][1] + w;
		for(int k = 1; k<d && board[next_h][next_w] != '#'; k++){	
			cnt++;
			next_h += mmove[i][0];
			next_w += mmove[i][1];
		}
	}
	return cnt + 1;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--){
		int mmax = 1;
		scanf("%d %d %d", &m, &n, &d);
		memset(board, 0, sizeof(board));
		getchar();

		for (int i = 0; i < n; i++)	gets(board[i]);
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (board[i][j] != '#'){
					int tmax = counting(i, j);
					if (tmax == mmax)
						ans++;
					else if (tmax > mmax){
						ans = 0;
						mmax = tmax;
					}
				}
			}
		}
		printf("%d %d\n", ans + 1, mmax);
	}
}