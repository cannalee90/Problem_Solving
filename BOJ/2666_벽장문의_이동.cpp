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
	int s, b, m;
	cin >> n;

	cin >> s >> b;
	cin >> m;
	vector<int> vi(m);
	int mmin = 987654321;
	for (int i = 0; i < m; i++) scanf("%d", &vi[i]);
	for (int i = 0; i < (1 << m); i++){
		int ans = 0;
		int d1 = s;
		int d2 = b;
		int idx = 0;
		for (int j = 1; j < (1 << m); j *= 2){
			if (i & j){
				ans += abs(vi[idx] - d1);
				d1 = vi[idx];
			}
			else{
				ans += abs(vi[idx] - d2);
				d2 = vi[idx];
			}
			idx++;
		}
		mmin = min(ans, mmin);
	}
	cout << mmin << endl;
}