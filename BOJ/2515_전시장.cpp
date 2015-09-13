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

int dp[20000001];

inline bool cmp(const pair<int, int > &a, const pair<int, int > &b){
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	vector<pair<int, int > > vp(n);
	for (int i = 0; i < n; i++)	scanf("%d %d", &vp[i].first, &vp[i].second);
	sort(vp.begin(), vp.end(), cmp);
	int idx = 0;
	for (int i = vp[0].first; i <= vp[n - 1].first; i++){
		dp[i] = dp[i - 1];
		if (vp[idx].first == i){
			dp[i] = max(dp[i], dp[i - m] + vp[idx].second);
			idx++;
			while (idx < n && vp[idx].first == i)
				idx++;
		}
	}
	cout << dp[vp[n - 1].first] << endl;
}