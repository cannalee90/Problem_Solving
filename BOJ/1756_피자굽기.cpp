#include <iostream>
#include <utility>
#include <functional>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

#define INF 987654321


int main(){
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<int> oven(n);
	vector<int> pizza(m);

	vector<int> mmin(n, INF); 
	for (int i = 0; i < n; i++)
		scanf("%d", &oven[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &pizza[i]);
	for (int i = 0; i < n; i++) {
		if (i != 0)
			mmin[i] = min(mmin[i - 1], oven[i]);
		else
			mmin[i] = oven[i];
	}
	int idx = 0;
	int  ans;
	for (int i = n - 1; i >= 0 && idx < m; i--)  {
		if (mmin[i] >= pizza[idx]){
			ans = i;
			idx++;
		}
	}
	if (idx != m)
		puts("0");
	else
		printf("%d\n", ans + 1);
}

