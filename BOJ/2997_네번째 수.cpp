#include <iostream>
#include <functional>
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

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	int num[3];
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num + 3);
	int b = num[2] - num[1];
	int a = num[1] - num[0];
	if (b == a)
		cout << num[2] + b << endl;
	else if (b > a)
		cout << num[2] - a << endl;
	else
		cout << num[1] - b << endl;
}