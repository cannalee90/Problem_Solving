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

int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	string str1, str2;
	cin >> str1 >> str2;
	str1 += str2;
	int matched = 0;
	vector<int> ret;
	vector<int> partial(str1.size(), 0);
	for (int i = 1; i < str1.size(); i++){
		while (matched != 0 && str1[i] != str1[matched])
			matched = partial[matched - 1];
		if (str1[matched] == str1[i]){
			matched++;
			partial[i] = matched;
		}
	}
	int k = str1.size();
	ret.push_back(str1.size());
	while (partial[k - 1] > 0){
		ret.push_back(partial[k - 1]);
		k = partial[k - 1];
	}
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++){
		cout << ret[i] << " ";
	}
	cout << endl;
}