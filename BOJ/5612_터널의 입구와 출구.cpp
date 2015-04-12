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
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int cur;
	int ans = -1;
	cin >> n >> cur;
	for (int i = 0; i < n; i++){
		int in, out;
		cin >> in >> out;
		cur += in - out;
		if (cur < 0){
			cout << "0" << endl;
			return 0;
		}
		else
			ans = max(ans, cur);
	}
	cout << ans << endl;
}