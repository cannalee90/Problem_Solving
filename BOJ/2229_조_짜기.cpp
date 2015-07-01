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

ll get_min(vector<int> &tree, int left, int right){
	int ret = INT_MAX;
	while (left <= right){
		if (left % 2 == 1) ret = min(tree[left++], ret);
		if (right % 2 == 0) ret = min(tree[right--], ret);
		left /= 2;
		right /= 2;
	}
	return ret;
}

ll get_max(vector<int> &tree, int left, int right){
	int ret = INT_MIN;
	while (left <= right){
		if (left % 2 == 1) ret = max(tree[left++], ret);
		if (right % 2 == 0) ret = max(tree[right--], ret);
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
	int idx = get_idx(n);
	int data[1001];
	ll dp[1001] = {};
	vector<int> mmin(idx * 2, INT_MAX);
	vector<int> mmax(idx * 2, INT_MIN);
	for (int i = 0; i <n; i++){
		scanf("%d", &data[i + 1]);
		mmax[i + idx] = data[i + 1];
		mmin[i + idx] = data[i + 1];
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			mmin[i] = min(mmin[i * 2], mmin[i * 2 + 1]);
			mmax[i] = max(mmax[i * 2], mmax[i * 2 + 1]);
		}
		idx /= 2;
	}
	data[0] = 0;
	idx = get_idx(n);
	for (int i = 1; i <=n; i++){
		for (int j = 1; j <= i; j++){
			int left = j - 1 + idx;
			int right = i - 1 + idx;
			dp[i] = max(dp[i], dp[j - 1] + get_max(mmax, left, right ) - get_min(mmin, left, right));
		}
	}
	cout << dp[n] << endl;
}