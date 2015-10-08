#include <iostream>
#include <fstream>
#include <string>
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


int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--) {

		int n, m;
		int x = 0;
		int y = 0;
		int idx = 0;

		cin >> n;

		vector<pair<int, int > > temp;
		vector<pair<int, int > > vp(n);
		vector<pair<int, int > > res;

		for (int i = 0; i < n; i++)
			scanf("%d %d", &vp[i].first, &vp[i].second);

		sort(vp.begin(), vp.end());

		while (idx < n) {

			if (vp[idx].first == x) {

				while (idx < n && vp[idx].first == x) {
					temp.push_back(vp[idx++]);
				}

				sort(temp.begin(), temp.end());

				if (temp.front().second < y) {
					reverse(temp.begin(), temp.end());
				}

				for (int i = 0; i < temp.size(); i++)  {
					res.push_back(temp[i]);
					y = temp[i].second;
				}
				temp.clear();
				if (idx < n) {
					temp.push_back(vp[idx]);
					x = vp[idx].first;
					idx++;
				}
			}
			else {
				res.push_back(temp.front());
				y = temp.front().second;
				temp.clear();
				if (idx < n) {
					temp.push_back(vp[idx]);
					x = vp[idx].first;
					idx++;
				}

			}
		}

		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int p;
			scanf("%d", &p);
			printf("%d %d\n", res[p - 1].first, res[p - 1].second);
		}
	}
}