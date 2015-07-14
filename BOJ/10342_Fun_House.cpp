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
char board[30][30];
int n, m, k;
int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int cnt = 1;
	while (cin >> m >> n){
		int k = 0;
		if (n == 0 && m == 0) break;
		int h, w;
		memset(board, 0, sizeof(board));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> board[i][j];
				if (board[i][j] == '*'){
					h = i;
					w = j;
				}
			}
		}
		if (h == 0 ) k = 1;
		else if (h == n - 1) k = 2;
		else if (w == 0) k = 0;
		else k = 3;
		while (board[h][w] != 'x'){
			if (board[h][w] == '/'){
				if (k == 0) k = 2;
				else if (k == 1) k = 3;
				else if (k == 2) k = 0;
				else if (k == 3) k = 1;
			}
			else if (board[h][w] == '\\'){
				if (k == 0) k = 1;
				else if (k == 1) k = 0;
				else if (k == 2) k = 3;
				else if (k == 3) k = 2;

			}
			h += mmove[k][0];
			w += mmove[k][1];
		}
		printf("HOUSE %d\n", cnt++);
		board[h][w] = '&';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << board[i][j];
			}
			cout << endl;
		}
	}
}