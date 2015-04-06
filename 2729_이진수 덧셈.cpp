#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
	int t;
	cin >> t;
	while (t--){
		string a, b;
		vector<int> ans(82, 0);
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		if (a.size() > b.size())
			swap(a, b);
		for (int  i = 0; i < a.size(); i++){
			ans[i] += a[i] - '0' + b[i] - '0';
			if (ans[i] > 1){
				ans[i] -=2;
				ans[i + 1] ++;
			}

		}
		
		for (int i = a.size(); i < b.size(); i++){
			ans[i] += b[i] - '0';
			if (ans[i] > 1){
				ans[i] -=2;
				ans[i + 1] ++;
			}
		}
		bool flag = true;
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++){
			if (ans[i])
				flag = false;
			if (!flag)
				cout << ans[i];
		}
		if (flag)
			cout << "0";
		cout << endl;
	}
}