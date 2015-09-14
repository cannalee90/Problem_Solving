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
int n, t;
int board[10][10];

bool isPossible(int i, int j, int k){
	if (i + k > 6 || j + k > 6) return false;
	else return true;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int cnt = 1;

	vector<int> paper(7);
	for (int i = 1; i <= 6; i++) cin >> paper[i];
	while (1){
		memset(board, 0, sizeof(board));
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++){
				for (int k = 5; k >= 1; k--){
					if (paper[k] == 0) continue;
					if (board[i][j] == 0 && isPossible(i, j, k)){
						for (int p = i; p < i + k; p++){
							for (int h = j; h < j + k; h++)
								board[p][h] = 1;
						}
						paper[k]--;
						//for (int p = 0; p < 6; p++) {
						//	for (int h = 0; h < 6; h++){
						//		cout << board[p][h];
						//	}
						//	cout << endl;
						//}
						//puts("");
					}
				}
			}
		}
		if (*max_element(paper.begin(), paper.end() - 1) == 0) break;
		else cnt++;
	}
	cout << cnt + paper[6] << endl;
}