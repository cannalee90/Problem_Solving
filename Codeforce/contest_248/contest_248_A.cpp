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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int a[2] = { 0 };
	vector<int> data;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		if (t1 == 100)
			a[0]++;
		else
			a[1] ++;
	}
	if (a[1] % 2 == 1 && a[0] % 2 == 1)
		cout << "NO" << endl;
	else if (a[0] % 2 == 1 && a[1] % 2 == 0)
		cout << "NO" << endl;
	else if (a[0] == 0 && a[1] % 2 != 0)
		cout << "NO" << endl;
	else if (a[1] == 0 && a[0] % 2 != 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
}