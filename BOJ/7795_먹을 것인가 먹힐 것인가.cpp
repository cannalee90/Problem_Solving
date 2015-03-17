#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>
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
		int n, m;
		int ans = 0;
		vector<int> a;
		vector<int> b;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			int t1;
			cin >> t1;
			a.push_back(t1);
		}
		for (int j = 0; j < m; j++){
			int t1;
			cin >> t1;
			b.push_back(t1);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++){
			vector<int>::iterator itor = lower_bound(b.begin(), b.end(), a[i]);
			ans += itor - b.begin();
		}
		cout << ans << endl;
	}
}