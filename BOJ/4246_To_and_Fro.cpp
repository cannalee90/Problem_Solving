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

typedef long long ll;


using namespace std;

int n, m, test;
int mmove[2] = { 1, -1 };

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (true){
		char board[200][25];
		memset(board, 0, sizeof(board));
		string str;
		cin >> n;
		if (n == 0) return 0;
		cin >> str;
		int row = 0, col = 0;
		for (int i = 0; i < str.size(); i++){
			board[row][col] = str[i];
			col += mmove[row % 2];
			if (col == n || col == -1){
				row++;
				if (row % 2 == 1) col = n - 1;
				else col = 0;
			}

		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < row; j++){
				printf("%c", board[j][i]);
			}
		}
		printf("\n");
	}
}