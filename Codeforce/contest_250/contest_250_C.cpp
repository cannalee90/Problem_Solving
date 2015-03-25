#include<iostream>
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
	int n, m;
	cin >> n >> m;
	vector<int> data(n + 1);
	vector<vector<int > > graph(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> data[i];
	}
	int ans = 0;
	for (int j = 0; j<m; j++){
		int t1, t2;
		cin >> t1 >> t2;
		ans += min(data[t1], data[t2]);
	}
	cout << ans << endl;
}