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

using namespace std;
typedef long long ll;

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<ll> &tree, int idx, int val){
	tree[idx] += val;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

ll get_sum(vector<ll> &tree, int left, int right){
	ll sum = 0;
	while (left <= right){
		if (left % 2 == 1) sum += tree[left++];
		if (right % 2 == 0) sum += tree[right--];
		left /= 2;
		right /= 2;
	}
	return sum;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, idx, m;
	scanf("%d", &n);
	idx = get_idx(n);
	vector<ll> tree(idx * 2);
	for (int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		update(tree, i + idx, val);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int q, a, val;
		scanf("%d", &q);
		if (q == 1){
			scanf("%d %d", &a, &val);
			update(tree, a + idx - 1, val);
		}
		else {
			scanf("%d", &val);
			int left = idx, right = idx + n - 1, mid, ans;
			while (left <= right){
				mid = (left + right) / 2;
				ll sum = get_sum(tree, idx, mid);
				if (sum >= val){
					right = mid - 1;
					ans = mid;
				}
				else
					left = mid + 1;
			}
			printf("%d\n", ans - idx + 1);
		}
	}
}