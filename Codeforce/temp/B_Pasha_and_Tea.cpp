#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	double n, w;
	cin >> n >> w;
	vector<int> vi(n * 2);
	for (int i = 0; i < n * 2; i++) scanf("%d", &vi[i]);
	sort(vi.begin(), vi.end());
	int idx = n;
	double val = min((double)vi[0], (double)vi[idx] / (double)2);
	val *= (double)3 * n;
	printf("%.10lf", min(val, w));
}