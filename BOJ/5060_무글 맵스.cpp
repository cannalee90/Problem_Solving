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

double err[300][300];
double dp[300][300];


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n, m;
		scanf("%d %d", &n, &m);
		vector<double> vd(n);
		for (int i = 0; i < n; i++) 
			scanf("%lf", &vd[i]);

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				dp[i][j] = 987654321.0;
				err[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				for (int k = j - 1; k > i; k--){
					double temp = vd[i] + (vd[j] - vd[i]) * (double)(k - i) / (double)(j - i);
					err[i][j] += fabs(temp - vd[k]);
				}
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i < m; i++){
			for (int j = i; j < n; j++){
				for (int k = j; k >=i; k--){
					dp[i][j] = min(dp[i][j], dp[i - 1][k- 1] + err[k - 1][j]);
				}
			}
		}

		printf("%0.4lf\n", dp[m - 1][n - 1] / n );
	}
}