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
int t;

int mmove[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 },
					{ 0, -1 }, { 0, 1 },
					{ 1, -1 }, { 1, 0 }, { 1,1 } };

int main(){
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	char map[1011][1011] = {};
	int ans[1011][1011] = {};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (map[i][j] != '.'){
				for (int k = 0; k < 8; k++){
					ans[i + mmove[k][0]][j + mmove[k][1]]+= map[i][j] - '0';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (map[i][j] != '.')
				cout << "*";
			else{
				if (ans[i][j] >= 10)
					cout << 'M';
				else
					cout << ans[i][j];
			}
		}
		cout << endl;
	}
}