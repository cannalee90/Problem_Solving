#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	const int limit = 10000;
	vector<int> Prime;
	vector<bool> P(limit + 1, true);
	for (int i = 2; i <=limit; i++){
		if (P[i]){
			Prime.push_back(i);
			for (int j = i; j <= limit; j += i){
				P[j] = false;
			}
		}
	}
	cin >> n;
	int min_gap = INT_MAX;
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		int ans_a = -20000;
		int ans_b = 0;
		for (int j = 0; j < Prime.size(); j++){
			if (m - Prime[j] <= 0) break;
			if (binary_search(Prime.begin(), Prime.end(), m - Prime[j])){
				if (abs(Prime[j] - (m - Prime[j])) < abs(ans_a - ans_b))	{
					ans_a = Prime[j];
					ans_b = m - Prime[j];
				}
			}
		}
		if (ans_a > ans_b) swap(ans_a, ans_b);
		cout << ans_a << " " << ans_b << endl;
	}
	
}