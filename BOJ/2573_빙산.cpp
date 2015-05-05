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

vector<vector<int> > iceberg;
vector<vector<bool > > visited;
vector<vector<int> > counting;

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int n, m;

bool isPossible(int h, int w){
	if (h < 1 || w < 1 || h > n || w > m) return false;
	if (iceberg[h][w] == 0 || visited[h][w] == true) return false;
	return true;

}

void dfs(int height, int width){
	for (int i = 0; i < 4; i++){
		int h = height + mmove[i][0];
		int w = width + mmove[i][1];
		if (isPossible(h, w)){
			visited[h][w] = true;
			dfs(h, w);
		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int area = 0;
	cin >> n >> m;
	iceberg = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> iceberg[i][j];
			area++;
		}
	}

	int ans = 1;
	while (true){
		counting = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (iceberg[i][j] == 0) continue;
				for (int k = 0; k < 4; k++){
					int h = i + mmove[k][0];
					int w = j + mmove[k][1];
					if (iceberg[h][w] == 0){
						counting[i][j]++;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				iceberg[i][j] -= counting[i][j];
				if (iceberg[i][j] < 0) iceberg[i][j] = 0;
			}
		}

		int cnt = 0;
		visited = vector<vector<bool > >(n + 1, vector<bool>(m + 1, false));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (iceberg[i][j] && visited[i][j] == false){
					visited[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt >= 2){

			cout << ans << endl;
			return 0;
		}
		else if (cnt == 0){
			cout << "0" << endl;
			return 0;
		}
		ans++;
	}
}