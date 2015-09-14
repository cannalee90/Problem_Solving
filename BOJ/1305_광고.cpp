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

const int M = 100010;
int n, t;

int main()

{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string str;
	cin >> n >> str;
	int matched = 0;
	vector<int> vi(str.size(), 0);
	for (int i = 1; i < str.size(); i++){
		while (matched > 0 && str[i] != str[matched])
			matched = vi[matched - 1];
		if (str[i] == str[matched]){
			matched++;
			vi[i] = matched;
		}
	}
	cout << n - vi[n - 1] << endl;
}