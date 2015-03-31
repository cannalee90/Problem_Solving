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
	int n, m;
	double mmax = 0;
	cin >> n >> m;
	vector<double> vertex(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> vertex[i];
	for (int i = 0; i < m; i++){
		int h, t, w;
		cin >> h >> t >> w;
		h = vertex[h];
		t = vertex[t];
		mmax = max((((double)h + (double)t) / (double)w), mmax);
	}
	printf("%.16lf\n", mmax);
	return 0;
}