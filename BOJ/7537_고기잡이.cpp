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

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m, l;
	scanf("%d %d %d", &m, &l, &n);
	vector<pair<int, int > > vp(n);
	vector<int> X(n), Y(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &vp[i].first, &vp[i].second);
		X[i] = vp[i].first;
		Y[i] = vp[i].second;
	}
	sort(vp.begin(), vp.end());
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	int ans = 1;
	for (int i = 0; i < X.size(); i++){
		for (int j = 0; j < Y.size(); j++){
			for (int k = 1; k < l / 2; k++){
				int x = X[i];
				int y = Y[j];
				int cnt = 0;
				for (int p = 0; p < vp.size(); p++){
					int h = (l / 2) - k;
					if (x <= vp[p].first && x + k >= vp[p].first && y <= vp[p].second && y + h >= vp[p].second){
						cnt++;
					}
					
				}
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans << endl;
}