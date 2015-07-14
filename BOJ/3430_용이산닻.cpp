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

void update(vector<int> &tree, int idx, int val){
	tree[idx] += val;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

void mupdate(vector<int> &tree, int idx, int val){
	tree[idx] = val;
	idx /= 2;
	while (idx){
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
		idx /= 2;
	}
}


int get_min(vector<int> &tree, int left, int right){
	int mmin = INT_MAX;
	while (left <= right){
		if (left % 2 == 1) mmin = min(mmin, tree[left++]);
		if (right % 2 == 0) mmin = min(mmin, tree[right--]);
		left /= 2;
		right /= 2;
	}
	return mmin;
}


int get_sum(vector<int> &tree, int left, int right){
	int sum = 0;
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
	int t;
	scanf("%d", &t);
	while (t--){

		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> days(m), ans(m), lake(n + 1);

		int idx = get_idx(m);
		vector<int> tree(idx * 2);
		vector<int> mtree(idx * 2, INT_MAX);
		bool isSaved = true;
		for (int i = 0; i < m; i++)	scanf("%d", &days[i]);
		for (int i = 0; i < m; i++){
			if (days[i] == 0) {
				update(tree, i + idx, 1);
				mupdate(mtree, i + idx, i);
			}
			else{
				int left = lake[days[i]] + idx;
				int right = i + idx;
				if (get_sum(tree, left, right) == 0){
					isSaved = false;
					break;
				}
				else{
					int loc = get_min(mtree, left, right);
					update(tree, loc + idx, -1);
					mupdate(mtree, loc + idx, INT_MAX);
					ans[loc] = days[i];
					lake[days[i]] = i;
				}
			}
		}
		if (isSaved) {
			puts("YES");
			for (int i = 0; i < m; i++){
				if (days[i] == 0) 	{
					printf("%d ", ans[i]);
				}
			}
			puts("");
		}
		else{
			puts("NO");
		}
	}
}