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
	string str, ans;
	while (cin >> str) {
		string cmp;
		for (int i = 0; i < str.size(); i++){
			if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == '-' || (str[i] >= 'a' && str[i] <= 'z'))
				cmp += str[i];
		}
		if (ans.size() < cmp.size() && cmp != "E-N-D") ans = cmp;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << (char)tolower(ans[i]);
	puts("");
}