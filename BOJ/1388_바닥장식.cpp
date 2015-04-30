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

vector<vector<char> > board;
vector<vector<bool> > visited;

int n, m;

void width(int h, int w){
	if (w == m - 1) return;
	if (board[h][w] == board[h][w + 1] && visited[h][w + 1] == false){
		visited[h][w + 1] = true;
		width(h, w + 1);
	}
}

void height(int h, int w){
	if (h == n - 1) return;
	if (board[h][w] == board[h+ 1][w] && visited[h + 1][w] == false){
		visited[h + 1][w] = true;
		height(h + 1, w);
	}

}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	board = vector<vector<char> >(n, vector<char>(m, ' '));
	visited = vector<vector<bool> >(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (visited[i][j] == false){
				ans++;
				visited[i][j] = true;
				if (board[i][j] == '-')
					width(i, j);
				else
					height(i, j);
			}
		}
	}
	cout << ans << endl;
}