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

int n, m, t;

int wall[100][100];
bool visited[100][100];
int mmove[5][2] = { {}, { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 }};

int counting(int h, int w){
	queue<pair<int, int > > que;
	que.push(make_pair(h, w));
	visited[h][w] = true;
	int cnt = 1;
	while (!que.empty()){
		int here_h = que.front().first;	
		int here_w = que.front().second;
		que.pop();
		int p = 1;
		for (int i = 1; i <= 4; i++){
			if (!(wall[here_h][here_w] & p)){
				int there_h = here_h + mmove[i][0];
				int there_w = here_w + mmove[i][1];
				if (there_h < 1 || there_w < 1 || there_h > n || there_w > m) continue;
				if (!visited[there_h][there_w]){
					cnt++;
					visited[there_h][there_w] = true;
					que.push(make_pair(there_h, there_w));
				}
			}
			p <<= 1;
		}
	}
	return cnt;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> m >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> wall[i][j];
		}
	}
	memset(visited, 0, sizeof(visited));
	int cnt = 0, ans = 0;
	for (int i = 1; i <=n; i++){
		for (int j = 1; j <= m; j++){
			if (!visited[i][j]){
				cnt++;
				ans = max(ans, counting(i, j));
			}
		}
	}
	cout << cnt << endl << ans << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <=8; k <<=  1){
				if (wall[i][j] & k){
					wall[i][j] -= k;
					memset(visited, 0, sizeof(visited));
					ans = max(ans, counting(i, j));
					wall[i][j] += k;
				}
			}
		}
	}
	cout << ans << endl;
}
