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

int n, m, k;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	string str;
	cin >> str >> n;
	ll num = 0;
	for (int i = 0; i < str.size(); i++){
		num *= n;
		if (str[i] >= '0' && str[i] <= '9')
			num += str[i] - '0';
		else
			num += str[i] - 'A' + 10;
	}
	cout << num << endl;
}