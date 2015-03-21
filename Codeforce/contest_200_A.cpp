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
#endif
	int ans = 0;
	cin >> n;
	string a;
	cin >> a;
	ans++;
	char last = a[1];
	for (int i = 1; i < n; i++){
		cin >> a;
		if (a[0] == last)
			ans++;
		last = a[1];
	}
	cout << ans << endl;
}
