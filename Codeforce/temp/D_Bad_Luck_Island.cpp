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

double dp[110][110][110];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int r, s, p;
	cin >> r >> s >> p;
	dp[r][s][p] = 1;
	for (int i = r; i >= 0; i--){ //¹ÙÀ§
		for (int j = s; j >= 0; j--){//°¡À§
			for (int k = p; k >= 0; k--){//º¸
				if (j == 0 && k == 0) continue;
				if (j == 0 && i == 0) continue;
				if (i == 0 && k == 0) continue;
				int sw = i * j; //  i, °¡À§Áü
				int pw = j * k; //  k, º¸°¡ Áü
				int rw = i * k; // i, ¹ÙÀ§°¡ Áü
				int total = sw + pw + rw;

				if(i > 0) dp[i - 1][j][k] += dp[i][j][k] * ((double)(rw) / (double)(total));
				if(j > 0 )dp[i][j - 1][k] += dp[i][j][k] * ((double)(sw) / (double)(total));
				if(k > 0) dp[i][j][k - 1] += dp[i][j][k] * ((double)(pw) / (double)(total));
			}
		}
	}
	double rans = 0, sans = 0, pans = 0;
	for (int i = 1; i <= r; i++)  
		rans += dp[i][0][0];
	for (int i = 1; i <= s; i++)  
		sans += dp[0][i][0];
	for (int i = 1; i <= p; i++)  
		pans += dp[0][0][i];

	printf("%.10lf %.10lf %.10lf\n", rans, sans, pans);

}