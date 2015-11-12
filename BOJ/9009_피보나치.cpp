#include <iostream>
#include <utility>
#include <functional>
#include <limits.h>
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

typedef long long ll;
using namespace std;

#define limit  1000000000

int main(){
	freopen("input.txt", "r", stdin);
	vector<int> fibo;
	fibo.push_back(1);
	fibo.push_back(1);
	for (int i = 2; fibo[i - 1] + fibo[i - 2] <= limit; i++)
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)  {
		int m;
		cin >> m;
		vector<int> ans;
		while (m) {
			auto itor = upper_bound(fibo.begin() , fibo.end(), m);
			itor--;
			ans.push_back(*itor);
			m -= *itor;
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		puts("");
	}
}
