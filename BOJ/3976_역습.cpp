#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
int p1[100001];
int p2[100001];
int dr1[100001];
int dr2[100001];
int dp[100001][2];


int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		int n, l1, l2, s1, s2;		
		scanf("%d %d %d %d %d", &n, &l1, &l2, &s1, &s2);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", &p1[i]);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", &dr1[i]);

		for(int i = 0; i < n - 1; i++)
			scanf("%d", &p2[i]);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", &dr2[i]);
		dp[0][0] = l1;
		dp[0][1] = l2;
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][0] + dr1[i - 1], dp[i - 1][1] + p2[i - 1]);
			dp[i][1] = min(dp[i - 1][1] + dr2[i - 1], dp[i - 1][0] + p1[i - 1]);
			
		}
		cout << min(dp[n-1][0] + s1, dp[n-1][1] + s2) << endl;
	}
}