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

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, p;
	vector<int> width;
	vector<int> height;
	cin >> m >> n >> p;
	width.push_back(0);
	width.push_back(m);
	height.push_back(0);
	height.push_back(n);
	for (int i = 0; i < p; i++){
		int q, num;
		cin >> q >> num;
		if (q == 0) height.push_back(num);
		if (q == 1) width.push_back(num);
	}
	sort(height.begin(), height.end());
	sort(width.begin(), width.end());
	int hmax = 1;
	int wmax = 1;
	for (int i = 0; i < height.size() - 1; i++) hmax = max(hmax, height[i + 1] - height[i]);
	for (int i = 0; i < width.size() - 1; i++) wmax = max(wmax, width[i + 1] - width[i]);
	cout << hmax * wmax << endl;
}