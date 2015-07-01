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

int num1[1000001], num2[1000001];
int order[500001];

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<int> &tree, int idx){
	tree[idx] = 1;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int get_sum(vector<int> &tree, int left, int right){
	int ret = 0;
	while (left <= right){
		if (left % 2 == 1) ret += tree[left++];
		if (right % 2 == 0) ret += tree[right--];
		left /= 2;
		right /= 2;
	}
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &val);
		order[i] = val;
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &val);
		num2[val] = i;
	}
	ll ans = 0;
	int idx = get_idx(n);
	vector<int> tree(idx * 2);
	for (int i = 0; i < n; i++){
		ans += get_sum(tree, num2[order[i]] + idx, idx * 2 - 1);
		update(tree, num2[order[i]] + idx);
	}
	printf("%lld\n", ans);
}