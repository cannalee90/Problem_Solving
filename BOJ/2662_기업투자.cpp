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

using namespace std;
typedef long long ll;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int data[301][21] = {}, dp[301][21] = {}, a;
	int track[301][21] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		cin >> a;
		for (int j = 1; j <= m; j++){
			cin >> data[i][j];
		}
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			int mmax = INT_MIN;
			int a = 0;
			for (int k = 0; k <= j; k++){
				if (mmax < dp[k][i - 1] + data[j - k][i]){
					mmax = dp[k][i - 1] + data[j - k][i];
					a = j - k;
				}
			}
			dp[j][i] = mmax;
			track[j][i] = a;
		}
	}
	vector<int> ans;
	int b = n;
	for (int i = m; i >= 1; i--){
		ans.push_back(track[b][i]);
		b -= track[b][i];
	}
	cout << dp[n][m] << endl;
	for (int i = ans.size() - 1; i >= 0; i--){
		cout << ans[i] << " ";
	}
	puts("");
}	