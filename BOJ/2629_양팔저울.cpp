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

const int M = 15010;
int n, m, t;
bool DP[61][M];
int weight[100], length = 0;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> weight[i];
		length += weight[i];
	}
	DP[0][0] = true;
	sort(weight + 1, weight + n + 1);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < weight[i]; j++) 
			DP[i][j] = DP[i - 1][j];
		for (int j = weight[i]; j <= length; j++){
			if (DP[i - 1][j] == true)
				DP[i][j] = true;
			else
				DP[i][j] = DP[i - 1][j - weight[i]];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = length; j > length - weight[i]; j--)
			DP[n + i][j] = DP[n + i - 1][j];
		for (int j = length - weight[i]; j >= 1; j--){
			if (DP[n + i - 1][j] == true)
				DP[n + i][j] = true;
			else if (DP[n + i - 1][j + weight[i]] == true && DP[n + i - 1][j] == false){
				DP[n + i][j] = true;
			}

		}

	}
	cin >> m;
	for (int i = 0; i < m; i++){
		int q;
		cin >> q;
		if (DP[n * 2][q])
			cout << "Y ";
		else
			cout << "N ";
	}
	cout << endl;
}
