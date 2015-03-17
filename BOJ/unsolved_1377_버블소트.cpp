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

vector<int> data;
vector<int> tree;
int n;

void input(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		scanf("%d", &t1);
		data.push_back(t1);
	}
}

int get_idx(){
	int idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}
void make_tree(){
	int idx = get_idx();
	tree.resize(idx * 2 + 1, INT_MAX);
	for (int i = idx; i < idx + n; i++){
		tree[i] = data[i - idx];
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
		}
		idx /= 2;
	}
}

bool min_query(int pos){
	int left = pos +  get_idx();
	int right = n + get_idx();
	int mmin = tree[left];
	while (left <= right){
		if (left % 2 == 1)
			mmin = min(mmin, tree[left++]);
		if (right % 2 == 0)
			mmin = min(mmin, tree[right--]);
		left /= 2;
		right /= 2;
	}
	if (mmin == tree[left])
		return false;
	else
		return true;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int ans;
	input();
	make_tree();
	for (int i = 0; i < n; i++){
		if (min_query(i)){
			ans = i;
		}
	}

	cout << ans << endl;
}