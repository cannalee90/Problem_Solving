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


int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<int> &tree, int idx, int val){
	tree[idx] += val;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int get_sum(vector<int> &tree, int left, int right){
	int ssum = 0;
	while (left <= right){
		if (left % 2 == 1) ssum += tree[left++];
		if (right % 2 == 0) ssum += tree[right--];
		left /= 2;
		right /= 2;
	}
	return ssum;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	map<int, int> query;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int a_val, b_val;
		if (!query.count(a))
			query[a] = a;
		if (!query.count(b))
			query[b] = b;
		swap(query[a], query[b]);
	}
	vector<int> vi(query.size());
	vector<int> sorted(query.size());
	vector<int> tree(query.size() * 4);
	int idx = 0;
	for (map<int, int >::iterator itor = query.begin(); itor != query.end(); itor++){
		vi[idx] = itor->second;
		sorted[idx++] = itor->second;
	}
	sort(sorted.begin(), sorted.end());
	idx = get_idx(query.size());
	ll ans = 0;
	for (int i = 0; i < vi.size(); i++){
		int a = lower_bound(sorted.begin(), sorted.end(), vi[i]) - sorted.begin() + idx;
		ans += get_sum(tree, a, idx * 2 - 1);
		update(tree, a, 1);
	}
	for (int i = 0; i < vi.size(); i++){
		if (sorted[i] == vi[i]) continue;
		int mmin = max(sorted[i], vi[i]);
		int mmax = min(sorted[i], vi[i]);
		int differ = mmin - mmax - 1;
		ans += differ + (upper_bound(sorted.begin(), sorted.end(), mmax) - sorted.begin()) - (lower_bound(sorted.begin(), sorted.end(), mmin) - sorted.begin());

	}
	cout << ans << endl;
}