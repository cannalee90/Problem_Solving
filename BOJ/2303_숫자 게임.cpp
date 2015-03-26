#include <iostream>
#include <limits.h>
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

typedef long long ll;

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int mmax_1 = INT_MIN;
	int ans;
	int m;
	int n = 5;
	cin >> m;
	for (int k = 1; k <= m; k++){
		vector<int> data;
		for (int i = 0; i < n; i++){
			int t1;
			cin >> t1;
			data.push_back(t1);
		}
		for (int i = 0; i < 32; i++){
			int sum = 0;
			int cnt = 0;
			for (int j = 0; j < 5; j++){
				if (i & (1 << j)){
					sum += data[j];
					cnt++;
				}
				if (cnt == 3)
					break;
			}
			if (cnt == 3){
				if (sum % 10 >= mmax_1){
					mmax_1 = sum % 10;
					ans = k;
				}
			}
		}
	}
	cout << ans << endl;
}