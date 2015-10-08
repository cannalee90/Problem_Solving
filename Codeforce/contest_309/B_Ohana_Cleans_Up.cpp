#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

int n, m, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	map<string, int> ans;
	cin >> n;
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		ans[str]++;
	}
	int mmax = 0;
	map<string, int>::iterator itor = ans.begin();
	for (; itor != ans.end(); itor++)
		mmax = max(mmax, itor->second);
	cout << mmax << endl;
}