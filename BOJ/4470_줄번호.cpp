#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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

int n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string str;
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++){
		getline(cin, str);
		printf("%d. %s\n", i, str.c_str());
	}
}