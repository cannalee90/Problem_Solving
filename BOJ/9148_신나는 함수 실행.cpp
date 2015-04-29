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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);


#endif
	int DP[22][22][22];
	int a, b, c;
	for (int i = 0; i <= 20; i++){
		for (int j = 0; j <= 20; j++){
			for (int k = 0; k <= 20; k++){
				if (i == 0 || j == 0 || k == 0)
					DP[i][j][k] = 1;
				else
					DP[i][j][k] = 0;
			}
		}
	}
	for (int i = 1; i <= 20; i++){
		for (int j = 1; j <= 20; j++){
			for (int k = 1; k <= 20; k++){
				if (i < j && j < k)
					DP[i][j][k] = DP[i][j][k - 1] + DP[i][j - 1][k - 1] - DP[i][j - 1][k];
				else
					DP[i][j][k] = DP[i - 1][j][k] + DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1] - DP[i - 1][j - 1][k - 1];
			}
		}
	}

	while (1){
		cin >> a >> b >> c;
		if (a == b && b == c && a == -1) break;
		
		if (a <= 0 || b <= 0 || c <= 0){
			printf("w(%d, %d, %d) = 1\n", a, b, c);
			continue;
		}
		else if (a > 20 || b > 20 || c > 20){
			printf("w(%d, %d, %d) = %d\n", a, b, c, DP[20][20][20]);
			continue;
		}

		printf("w(%d, %d, %d) = %d\n", a, b, c, DP[a][b][c]);
	}
}