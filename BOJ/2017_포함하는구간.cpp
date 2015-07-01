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

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<int> &v, int idx, int val){
	v[idx] = val;
	idx /= 2;
	while (idx){
		v[idx] = v[idx * 2] + v[idx * 2 + 1];
		idx /= 2;
	}
}

int find(vector<int> &v, int val){
	vector<int>::iterator itor = lower_bound(v.begin(), v.end(), val);
	return itor - v.begin();
}

int get_sum(vector<int> &v, int left, int right){
	int ret = 0;
	while (left <= right){
		if (left % 2 == 1) ret += v[left++];
		if (right % 2 == 0) ret += v[right--];
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
	int n, ans = 0;
	scanf("%d", &n);
	vector<pair<int, int > > vp(n);
	vector<int> coor(n * 2);
	int idx = get_idx(n * 2);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &vp[i].first, &vp[i].second);
		coor[i * 2] = vp[i].first;
		coor[i * 2 + 1] = vp[i].second;
	}
	vector<int> tree(idx * 2 + 1);
	sort(coor.begin(), coor.end());
	sort(vp.begin(), vp.end());
	for (int i = 0; i < n; i++)
		update(tree, find(coor, vp[i].second) + idx, 1);
	for (int i = 0; i < n; i++){
		ans = max(ans, get_sum(tree, find(coor, vp[i].first) + idx, find(coor, vp[i].second) + idx));
		update(tree, find(coor, vp[i].second) + idx, 0);
	}
	cout << ans - 1<< endl;
}