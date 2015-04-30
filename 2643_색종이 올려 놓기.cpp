#include <iostream>
#include <utility>
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

inline bool cmpp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ans = 0;
	cin >> n;
	vector<pair<int, int> > paper(n + 1, pair<int, int>(0,0));
	paper[0].first = 10000;
	paper[0].second = 10000;
	for (int i = 1; i <= n; i++){
		int h, t;
		cin >> h >> t;
		paper[i].first = max(h, t);
		paper[i].second = min(h, t);
	}
	sort(paper.begin(), paper.end(), cmpp);
	vector<int> DP(n + 1, 0);
	for (int i = 1; i <= n; i++){
		int mmax = INT_MIN;
		for (int j = i - 1; j >= 0; j--){
			if (paper[i].first <= paper[j].first && paper[i].second <= paper[j].second)
				mmax = max(DP[j], mmax);
		}
		DP[i] = mmax + 1;
		ans = max(DP[i], ans);
	}
	cout << ans << endl;
}