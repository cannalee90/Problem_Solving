#include <iostream>
#include <limits.h>
#include<functional>
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

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
bool ground[100][100];
int n, m, t;

bool isPossible(int h, int w){
	if (h < 0 || h >= n || w < 0 || w >= m) return false;
	if (ground[h][w] == false) return false;
	return true;
}

void dfs(int h, int w){
	for (int i = 0; i < 4; i++){
		int there_h = h + mmove[i][0];
		int there_w = w +  mmove[i][1];
		if (isPossible(there_h, there_w)){
			ground[there_h][there_w] = false;
			dfs(there_h, there_w);
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int p;
		int ans = 0;
		scanf("%d %d %d", &m, &n, &p);
		memset(ground, 0, sizeof(ground));
		for (int i = 0; i < p; i++){
			int h, w;
			scanf("%d %d", &w, &h);
			ground[h + 1][w + 1] = true;
		}
		for (int i = 1; i <=n; i++){
			for (int j = 1; j <=m; j++){
				if (ground[i][j]){
					ground[i][j] = false;
					dfs(i, j);
					ans++;
				}
			}
		}
		
		cout << ans << endl;
	}
}