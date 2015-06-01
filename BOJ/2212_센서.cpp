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

int n, m, k;
int dp[1001][10001];


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	cin >> n >> k;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	sort(data.begin(), data.end());
	data.erase(unique(data.begin(), data.end()), data.end());
	for (int i = 1; i < data.size(); i++) dp[0][i] = data[i] - data[0];
	for (int i = 1; i <= k; i++){
		for (int j = i + 1; j < data.size(); j++){
			dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + (data[j] - data[j - 1]));
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[k - 1][data.size() - 1] << endl;
}