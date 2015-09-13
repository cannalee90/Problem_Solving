#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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

vector<int> failure_KMP(const string &str){
	int matched = 0;
	vector<int> partial(str.size(), 0);
	for (int i = 1; i < str.size(); i++){
		while (matched != 0 && str[i] != str[matched])
			matched = partial[matched - 1];
		if (str[i] == str[matched])
			partial[i] = ++matched;
	}
	return partial;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	int matched = 0;
	string str, rev_str;
	cin >> str;
	rev_str = str;
	reverse(rev_str.begin(), rev_str.end());
	vector<int> partial = failure_KMP(rev_str);
	for (int i = 0; i < str.size(); i++){
		while (matched != 0 && str[i] != rev_str[matched])
			matched = partial[matched - 1];
		if (str[i] == rev_str[matched]){
			++matched;
		}
	}
	cout << str.size() * 2 - matched << endl;
}