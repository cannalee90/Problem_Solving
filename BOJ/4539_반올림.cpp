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

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		ll num;
		ll digit = 10;
		cin >> num;
		while (num / digit){
			if ((num % digit) / (digit / 10) >= 5)
				num += digit;
			num /= digit;
			num *= digit;
			digit *= (long long)10;
		}
		cout << num << endl;
	}
}