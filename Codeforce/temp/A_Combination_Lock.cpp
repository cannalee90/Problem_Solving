#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ans = 0;
	cin >> n;
	vector<int> vi(n), vii(n);
	for (int i = 0; i < n; i++) 
		scanf("%1d", &vi[i]);
	for (int i = 0; i < n; i++)
		scanf("%1d", &vii[i]);
	for (int i = 0; i < n; i++){
		ans += min(abs(vi[i] - vii[i]), (10 - max(vi[i], vii[i])) + min(vi[i], vii[i]));
	}
	cout << ans << endl;	
}