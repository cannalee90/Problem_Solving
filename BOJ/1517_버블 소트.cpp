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
	int n;
	scanf("%d", &n);
	vector<int> data(n);
	vector<int> sorted(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
		sorted[i] = data[i];
	}
	sort(sorted.begin(), sorted.end());
	vector<int>::iterator itor;
	int ans = 0;
	for (int i = 0; i < n; i++){
		itor = lower_bound(sorted.begin(), sorted.end(), data[i]);
		int val = itor - sorted.begin();
		if (val - i > 0){
			ans += val - i + 1;
		}
	}
	cout << ans   << endl;
}

