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

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<int> &tree, int idx, int val){
	tree[idx] = val;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

ll get_sum(vector<int> &tree, int left, int right){
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
	int t;
	cin >> t;
	while (t--){
		int n;
		ll ans = 0;
		int seq[100001], mapping[100001];
		memset(seq, 0, sizeof(seq));
		memset(mapping, 0, sizeof(mapping));
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &seq[i]);
		for (int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			mapping[num] = i;
		}
		
		int idx = get_idx(n);
		vector<int> ssum(idx * 2);
		for (int i = 0; i < n; i++){
			int left = idx + mapping[seq[i]];
			int right = idx * 2 - 1;
			ans += get_sum(ssum, left, right);
			update(ssum, left, 1);
		}
		printf("%lld\n", ans);
	}
}