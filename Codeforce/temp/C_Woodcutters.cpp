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

const int M = 100010;
int n, t;

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

int get_max(vector<ll> &tree, int left, int right){
	ll mmax = INT_MIN;
	while (left <= right){
		if (left % 2 == 1) mmax = max(mmax, tree[left++]);
		if (right % 2 == 0) mmax = max(mmax, tree[right--]);
		left /= 2;
		right /= 2;
	}
	return mmax;
}

void update(vector<ll> &tree, int idx, int val){
	if (tree[idx] < val){
		tree[idx] = val;
		idx /= 2;
		while (idx){
			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
			idx /= 2;
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<pair<ll, ll > > data(n);
	vector<ll> coor;
	for (int i = 0; i < n; i++){
		cin >> data[i].first >> data[i].second;
		coor.push_back(data[i].first - 1);
		coor.push_back(data[i].first + 1);
		coor.push_back(data[i].first - data[i].second);
		coor.push_back(data[i].first + data[i].second);
		coor.push_back(data[i].first);
	}
	sort(data.begin(), data.end());
	sort(coor.begin(), coor.end());
	coor.erase(unique(coor.begin(), coor.end()), coor.end());
	vector<ll>tree(get_idx(coor.size() * 2));
	int idx = get_idx(coor.size());
	for (int i = 0; i < n; i++){
		int left = idx, right = lower_bound(coor.begin(), coor.end(), data[i].first - data[i].second) - coor.begin() + idx;
		int left_1 = idx, right_1 = lower_bound(coor.begin(), coor.end(), data[i].first) - coor.begin() + idx;
		int a = get_max(tree, left, right) + 1;
		int b = get_max(tree, left_1, right_1) + 1;
		int c = lower_bound(coor.begin(), coor.end(), data[i].first - 1) - coor.begin() + idx;
		int d = lower_bound(coor.begin(), coor.end(), data[i].first + data[i].second) - coor.begin() + idx;
		
		update(tree, c, a);
		update(tree, d, b);

		int left_2 = idx, right_2 = lower_bound(coor.begin(), coor.end(), data[i].first) - coor.begin() + idx;
		int g = lower_bound(coor.begin(), coor.end(), data[i].first) - coor.begin() + idx;
		int f = get_max(tree, left_2, right_2);
		
		update(tree, g, f);
	}
	cout << get_max(tree, idx, idx * 2 - 1) << endl;
}