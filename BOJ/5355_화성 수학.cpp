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
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	cin >> t;
	while (t--){
		double num;
		cin >> num;
		char a;
		while ((a = getchar()) != '\n'){
			if (a == -1) break;
			if (a == '@')
				num *= (double)3;
			if (a == '%')
				num += (double)5;
			if (a == '#')
				num -= (double)7;
		}
		printf("%.2lf\n", num + 0.00000001);
	}
}
