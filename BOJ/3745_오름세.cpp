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


int get_max(vector<int> &tree, int left, int right){
	int sum = 0;
	while (left <= right){
		if (left % 2 == 1) sum = max(tree[left++], sum);
		if (right % 2 == 0) sum = max(tree[right--], sum);
		left /= 2;
		right /= 2;
	}
	return sum;
}

void update(vector<int> &tree, int idx, int val){
	tree[idx] = val;
	idx /= 2;
	while (idx){
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	while (cin >> n){
		vector<int> vi(n), vii(n), dp(n), prev(n);
		vector<int>::iterator itor;
		for (int i = 0; i < n; i++) 	{
			scanf("%d", &vi[i]);
			vii[i] = vi[i];
		}
		vii.push_back(INT_MIN);
		sort(vii.begin(), vii.end());
		vii.erase(unique(vii.begin(), vii.end()), vii.end());
		int idx = get_idx(vii.size());
		vector<int> tree(idx * 2);
		int ans = 1;
		for (int i = 0; i < vi.size(); i++){
			int left = idx;
			itor = lower_bound(vii.begin(), vii.end(), vi[i]);
			itor--;
			int right = (itor - vii.begin())+ idx;
			dp[i] = get_max(tree, left, right) + 1;
			right++;
			update(tree, right, dp[i]);
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
}	
