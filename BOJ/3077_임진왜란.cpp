#include <iostream>
#include <utility>
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
#include <functional>

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int n;
	int cnt = 0;
	string str;
	map<string, int> data;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> str;
		data.insert(make_pair(str, cnt++));
	}
	vector<int> vi(n);
	for (int i = 0; i < n; i++){
		cin >> str;
		vi[i] = data[str];
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1;  j < n; j++){
			if (vi[i] < vi[j])
				ans++;
		}
		cout << ans << endl;
	}
	cout << ans << "/" << (n * (n - 1)) / 2 << endl;
}