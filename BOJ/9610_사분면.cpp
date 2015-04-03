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
	int ans[5] = {};
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1, t2;
		cin >> t1 >> t2;
		if (t1 > 0 && t2 > 0)
			ans[1]++;
		else if (t1 < 0 && t2 > 0)
			ans[2]++;
		else if (t1 < 0 && t2 < 0)
			ans[3] ++;
		else if (t1 > 0 && t2 < 0)
			ans[4]++;
		else
			ans[0]++;
	}
	for (int i = 1; i <= 4; i++)
		printf("Q%d: %d\n", i, ans[i]);
	printf("AXIS: %d\n", ans[0]);
}