#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
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

vector<vector<int > > tree;

int n, k;
int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

int finding(int idx, int val){
	return (int)(lower_bound(tree[idx].begin(), tree[idx].end(), val) - tree[idx].begin());
}

int get_num(int left, int right, int val){
	int ret = 0;
	while (left <= right){
		if (left % 2 == 1) 
			ret += finding(left++, val);
		if (right % 2 == 0) 
			ret += finding(right--, val);
		left /= 2;
		right /= 2;
	}
	return ret;
}

void maketree(){
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, num, m;
	scanf("%d %d", &n, &m);
	int idx = get_idx(n);
	vector<int> seq;
	tree = vector<vector<int > >(idx * 2);

	for (int i = 0; i < n; i++){
		scanf("%d", &num);
		tree[idx + i].push_back(num);
		seq.push_back(num);
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			for (int j = 0; j < tree[i * 2].size(); j++)
				tree[i].push_back(tree[i * 2][j]);
			for (int j = 0; j < tree[i * 2 + 1].size(); j++)
				tree[i].push_back(tree[i * 2 + 1][j]);
			sort(tree[i].begin(), tree[i].end());

		}
		idx /= 2;
	}
	idx = get_idx(n);
	for (int i = 0; i < m; i++){
		int se, en, k;
		int left = -1000000000, right = 1000000000, mid, ans;
		scanf("%d %d %d", &se, &en, &k);
		while (left <= right){
			mid = (left + right) / 2;
			int smaller_num = get_num(se + idx - 1, en + idx - 1, mid);
			if (smaller_num < k){
				left = mid + 1;
				ans = mid;
			}
			else{
				right = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
}
