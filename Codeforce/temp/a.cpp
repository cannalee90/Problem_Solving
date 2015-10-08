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

int n, s;
vector < pair < int, int > > data;
int dp[20000020];
int main()
{
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		data.push_back(make_pair(a, b));
	}
	sort(data.begin(), data.end());

	dp[0] = 0;
	int res = 0;
	for (int i = 0; i <= 20000000; i++)
	{
		if (dp[i] == -1) continue;
		for (int j = 0; j < n; j++)
		{
			if (i + s > data[j].first) continue;
			dp[data[j].first] = max(dp[data[j].first], dp[i] + data[j].second);
			res = max(res, dp[data[j].first]);
		}
	}
	printf("%d\n", res);
}