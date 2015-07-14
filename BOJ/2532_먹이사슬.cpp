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

int n, t;
int dp[500001];

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

inline bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

void update(vector<int> &tree, int idx, int val){
	tree[idx] = val;
	idx /= 2;
	while (idx){
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}

int get_max(vector<int> &tree, int left, int right){
	int ret = INT_MIN;
	while (left <= right){
		if (left % 2 == 1) ret = max(ret, tree[left++]);
		if (right % 2 == 0) ret = max(ret, tree[right--]);
		left /= 2;
		right /= 2;
	}
	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<pair<int, int > >vp(n);
	vector<int> coor;
	for (int i = 0; i < n; i++){
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		vp[i].first = t2;
		vp[i].second = t3;
		coor.push_back(t2);
		coor.push_back(t3);
	}
	sort(vp.begin(), vp.end(), cmp);
	sort(coor.begin(), coor.end());
	coor.erase(unique(coor.begin(), coor.end()), coor.end());
	vp.erase(unique(vp.begin(), vp.end()), vp.end());

	int idx = get_idx(coor.size());
	vector<int> tree(idx * 2);
	int ans = 1;

	for (int i = 0; i < vp.size(); i++){
		int loc = lower_bound(coor.begin(), coor.end(), vp[i].second) - coor.begin();
		dp[i] = get_max(tree, loc + idx, idx * 2 - 1) + 1;
		update(tree, loc + idx, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
