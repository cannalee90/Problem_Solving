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

void update(vector<ll> &tree, int idx, int val){
	tree[idx] += val;
	idx /= 2;
	if (tree[idx] < 0) tree[idx] = 0;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

ll get_sum(vector<ll> &tree, int left, int right){
	ll ret = 0;
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
	int n;
	scanf("%d", &n);
	int idx = 1;
	while (idx < 1000000) idx *= 2;
	vector<ll> tree(idx * 2, 0);

	for (int i = 0; i < n; i++){
		int q, a, b;
		scanf("%d", &q);
		if (q == 2){
			scanf("%d %d", &a, &b);
			update(tree, a + idx - 1, b);
		}
		else{
			scanf("%d", &a);
			int left = idx, right = idx * 2 - 1, mid, ans = INT_MAX;
			while (left <= right){
				mid = (left + right) / 2;
				ll sum = get_sum(tree, idx, mid);
				if (sum >= a){
					right = mid - 1;
					ans = min(mid, ans);
				}
				else{
					left = mid + 1;
				}
			}
			printf("%d\n", ans - idx + 1);
			update(tree, ans, -1);
		}
	}
}