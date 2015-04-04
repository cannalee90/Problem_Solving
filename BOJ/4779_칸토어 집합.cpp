#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

vector<bool> line;
int n;

void cantoer(int left, int right, int range){
	int mid = (left + right) / 2;
	for (int i = mid - (range/ 2); i <= mid + (range/ 2); i++){
		line[i] = false;
	}
	if (range == 1)
		return;
	cantoer(left, mid - (range / 2) - 1, range / 3);
	cantoer(mid + (range / 2 ) + 1, right, range / 3);
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);m
	freopen("output.txt", "w", stdout);
#endif
	while (cin >> n){
		if (n == 0){
			cout << "-" << endl;
			continue;
		}
		n = pow(3, n);
		line.resize(n + 1, true);
		cantoer(1, n, n / 3);
		for (int i = 1; i <= n; i++){
			if (line[i])
				cout << "-";
			else
				cout << " ";
		}
		cout << endl;
	}
}