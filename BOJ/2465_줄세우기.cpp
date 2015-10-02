#include <iostream>
#include <fstream>
#include <string>
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

int get_idx(int p){
	int idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<int> &tree, int idx, int val){
	tree[idx] += val;
	idx /= 2;
	while (idx) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int idx = get_idx(n);
	vector<int> data(n),  ans(n), tree(idx * 2), series(n);

	for (int i = 0; i < n; i++)
		cin >> data[i];
	for (int i = 0; i < n; i++)
		cin >> series[i];

	sort(data.begin(), data.end());

	for (int i = 0; i < n; i++)
		update(tree, i + idx, 1);
	
	for (int i = n - 1; i >= 0; i--) {
		int val = series[i] + 1;
		int node = 1;
		while (node < idx) {
			if (tree[node * 2] >= val)
				node *= 2;
			else {
				val -= tree[node * 2];
				node = node * 2 + 1;
			}
		}
		ans[i] = node - idx;
		update(tree, node, -1);
	}

	for (int i = 0; i < n; i++)
		cout << data[ans[i]] << " ";
	puts("");
}