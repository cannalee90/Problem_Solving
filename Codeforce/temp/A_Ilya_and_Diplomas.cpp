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
	int n;
	int a, b, c;
	int sum = 0;
	vector<pair<int, int > > vp(3);
	cin >> n;
	for (int i = 0; i < 3; i++){
		cin >> vp[i].first >> vp[i].second;
		n -= vp[i].first;
	}
	a = vp[0].first;
	b = vp[1].first;
	c = vp[2].first;
	
	a += min(vp[0].second - vp[0].first, n);
	n -= (vp[0].second - vp[0].first);
	if (n < 0) n = 0;

	b += min(vp[1].second - vp[1].first, n);
	n -= (vp[1].second - vp[1].first);
	if (n < 0) n = 0;

	c += min(vp[2].second - vp[2].first, n);
	n -= (vp[2].second - vp[2].first);
	if (n < 0) n = 0;

	cout << a << " " << b << " " << c << endl;
}