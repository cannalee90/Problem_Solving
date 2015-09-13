#include<functional>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<string>
#include<limits>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

int dp[11][1 << 11];
char board[11][11];
int n, m;

int check(int current, int previous){
	for (int i = 1; i < (1 << m); i <<= 1){
		if ((current & i)){
			if ((previous & (i * 2)) || (previous & (i / 2)))
				return false;
		}
	}
	return true;
}
int visited[11] = { 0 };

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		memset(dp, 0, sizeof(dp));
		memset(dp, 0, sizeof(board));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < m; j++){
				cin >> board[i][j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < (1 << m); j++){
				int mmax = 0, bit = 0;
				bool isPossible = true;
				int idx = m - 1;
				for (int k = 1; k < (1 << m); k <<= 1){
					if ((j & k) && board[i][idx] == '.') bit++;
					if (j & k && j & (k << 1)){
						isPossible = false;
						break;
					}
					idx--;
				}
				if (!isPossible) continue;
				int a = 0;
				for (int k = 0; k < (1 << m); k++){
					if (check(j, k)){
						if (mmax < dp[i - 1][k]){
							mmax = max(dp[i - 1][k], mmax);
							a = k;
						}
						
					}
				}
				dp[i][j] = mmax + bit;
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << endl;
	}
}