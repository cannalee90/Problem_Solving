#include <iostream>
#include <fstream>
#include <string>
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

int maxsub(vector<int> &data){
	int ret = 0;
	vector<int> dp(data.size());
	(data[0] > 0) ? dp[0] = data[0] : data[0] = 0;
	ret = max(ret, dp[0]);
	for (int i = 1; i < data.size(); i++) {
		if (dp[i - 1] + data[i] > 0)
			dp[i] = dp[i - 1] + data[i];
		else
			dp[i] = 0;
		ret = max(dp[i], ret);
	}
	return ret;
}

int main() {
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		int ssum = 0;
		cin >> n;
		vector<int> data(n);
		vector<int> rdata(n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
			ssum += data[i];
			rdata[i] = data[i] * -1;
		}
		int a = maxsub(data);
		ssum += maxsub(rdata);
		cout << max(a, ssum) << endl;
	}
}