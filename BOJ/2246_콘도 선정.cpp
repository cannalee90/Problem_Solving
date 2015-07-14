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
	int n, ans = 0;
	scanf("%d", &n);
	vector<pair<int, int > > vp(n);
	for (int i = 0; i < n; i++) scanf("%d %d", &vp[i].first, &vp[i].second);
	sort(vp.begin(), vp.end());
	for (int i = 0; i < n; i++){
		bool isPossible = true;
		int hd = vp[i].first, hp = vp[i].second;
		for (int j = 0; j < n; j++){
			int td = vp[j].first, tp = vp[j].second;
			if (td < hd && hp >= tp){
				isPossible = false; break;
			}
			if (tp < hp && hd >= td){
				isPossible = false; break;

			}
		}
		if (isPossible) ans++;
	}
	cout << ans << endl;
}