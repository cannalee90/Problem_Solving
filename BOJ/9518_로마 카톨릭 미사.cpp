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
char church[60][60];
int mmove[8][2] = { { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

int cal(int h, int w){
	int cnt = 0;
	if(h != 0 && w != 0) church[h][w] = 'o';

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (church[i][j] == 'o'){
				for (int k = 0; k < 8; k++){
					if (church[i + mmove[k][0]][j + mmove[k][1]] == 'o')
						cnt++;
				}
			}
		}
	}
	church[h][w] = '.';
	return cnt;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> church[i][j];
		}
	}
	int ans = cal(0, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (church[i][j] == '.'){
				ans = max(ans, cal(i, j));
			}
		}
	}
	cout << ans / 2	<< endl;
}