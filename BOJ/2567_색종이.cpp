#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
int n, t;
int board[120][120], visited[120][120];
int mmove[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool isPossible(int h, int w){
	if (h < 0 || w < 0 || board[h][w] != 1) return false;
	else return true;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int h, w;
		cin >> h >> w;
		for (int j = h; j < h + 10; j++){
			for (int k = w; k < w + 10; k++){
				board[j][k] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 110; i++){
		for (int j = 0; j < 110; j++){
			if (board[i][j] == 0){
				for (int k = 0; k < 4; k++){
					int h = i + mmove[k][0], w = j + mmove[k][1];
					if (isPossible(h, w) && !(visited[h][w] & 1 << k)){
						visited[h][w] |= visited[h][w] | (visited[h][w] & 1 << k);
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}