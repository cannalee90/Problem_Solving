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
#include <cmath>


using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	int ans = 0, idx = 0;
	cin >> n >> m;
	vector<pair<int, int > > jewel(n);
	vector<int> bp(m);
	multiset<int> bp2;
	for (int i = 0; i < n; i++)
		cin >> jewel[i].second >> jewel[i].first;
	for (int i = 0; i < m; i++){
		cin >> bp[i];
		bp2.insert(bp[i]);
	}

	sort(jewel.begin(), jewel.end());

	reverse(jewel.begin(), jewel.end());

	for (int i = 0; i < n; i++) {
		auto itor = bp2.lower_bound(jewel[i].second);
		if (itor != bp2.end()) {
			ans += jewel[i].first;
			bp2.erase(itor);
		}
		
	}

	cout << ans << endl;
}
