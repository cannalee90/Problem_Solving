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
	int m;
	string s;
	cin >> s;
	cin >> m;
	vector<int> data;
	for (int i = 0; i < m; i++){
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	sort(data.begin(), data.end());
	for (int i = 0; i < s.size() / 2; i++){
		vector<int>::iterator itor = upper_bound(data.begin(), data.end(), i + 1);
		if ((itor - data.begin()) % 2 == 1){
			swap(s[i], s[s.size() - i - 1]);
		}
	}
	cout << s << endl;
}