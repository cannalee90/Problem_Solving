#include <iostream>
#include <fstream>
#include <string>
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

bool digitChange(int num, int digit) {
	vector<int> res;
	while (num) {
		res.push_back(num % digit);
		num /= digit;
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != res[res.size() - 1 - i])
			return false;
	}
	return true;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		bool isPal = false;
		for (int j = 2; j <= 64; j++) {
			if (digitChange(m, j)) {
				isPal = true;
				break;
			}
		}
		if (isPal)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}