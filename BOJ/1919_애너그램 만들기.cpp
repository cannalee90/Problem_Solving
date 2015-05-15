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
	string a, b;
	int ans = 0;
	int ac[30] = {}, bc[30] = {};
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)	ac[a[i] - 'a']++;
	for (int i = 0; i < b.size(); i++)	bc[b[i] - 'a']++;
	for (int i = 0; i < 30; i++)
		ans += abs(ac[i] - bc[i]);
	cout << ans << endl;
}
