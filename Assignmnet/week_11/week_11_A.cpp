#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <functional>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int n, m, t;

int data[501][501];
char table[501][501];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	cin >> t;
	while (t--){
		int num = 0, idx = 1;
		char t;
		memset(data, 0, sizeof(data));
		memset(table, 0, sizeof(table));

		cin >> n >> m;
		while (idx <= n){
			int cnt = 1;
			while (cnt <= m){
				cin >> num >> t;
				for (int i = 0; i < num; i++){
					table[idx][cnt + i] = t;
				}
				cnt += num;
			}
			idx++;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (table[i][j] == 'f')
					data[i][j] = data[i - 1][j] + 1;
				else
					data[i][j] = 0;
			}
		}
		int ans = INT_MIN;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				int height = data[i][j];
				for (int k = j; j >= 1; k--){
					if (data[i][k] == 0) break;
					if (data[i][k] < height)
						height = data[i][k];
					ans = max(ans, height * (j - k + 1));
				}
			}
		}
		cout << ans << endl;
	}
}