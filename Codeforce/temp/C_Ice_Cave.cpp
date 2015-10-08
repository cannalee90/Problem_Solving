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

vector<string> board;
int n, m;
int beginh, beginw;
int endh, endw;
bool isReach;
int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

inline bool isPossible(int h, int w){
	if (h < 0 || w < 0 || h >= n || w >= m) 
		return false;
	else 
		return true;
}

void bfs(int h, int w){
	queue<pair<int, int > > que;
	que.push(make_pair(h, w));
	vector<vector<int > > dis(n, vector<int>(m, INT_MAX));
	dis[h][w] = 0;
	while (!que.empty()){
		h = que.front().first;
		w = que.front().second;
		que.pop();
		if (h == endh - 1 && w == endw - 1){
			int cnt = 0;
			for (int i = 0; i < 4; i++){
				int nexth = h + mmove[i][0];
				int nextw = w + mmove[i][1];
				if (isPossible(nexth, nextw)){
					if (board[nexth][nextw] == '.' || (nexth == beginh - 1) && (nextw == beginw - 1))
						cnt++;
				}
			}
			if (cnt >= 2){
				isReach = true;
				return;
			}
		
		}
		for (int i = 0; i < 4; i++){
			int nexth = h + mmove[i][0];
			int nextw = w + mmove[i][1];
			if (isPossible(nexth, nextw)){
				if (board[nexth][nextw] == '.' && dis[h][w] + 1 < dis[nexth][nextw]){
					dis[nexth][nextw] = dis[h][w] + 1;
					que.push(make_pair(nexth, nextw));
				}
				else if (nexth == endh - 1 && nextw == endw - 1 && board[nexth][nextw] == 'X'){
					isReach = true;
					return; 
				}
			}
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	board = vector<string>(n);
	for (int i = 0; i < n; i++) cin >> board[i];
	cin >> beginh >> beginw >> endh >> endw;
	isReach = false;
	bfs(beginh - 1, beginw - 1);
	if (isReach) 
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}