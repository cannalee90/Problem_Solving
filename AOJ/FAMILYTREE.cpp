#include <iostream>
#include <utility>
#include <limits.h>
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

vector< int > parent;
vector<vector<int > > tree;
vector<int> depth;

void traversal(int here, int d){
	depth[here]  = d;
	for (int i = 0; i < tree[here].size(); i++){
		int there = tree[here][i];
		traversal(there, d + 1);
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m, root;
		scanf("%d %d", &n, &m);
		parent = vector<int>(n);
		tree = vector<vector<int > >(n);
		depth = vector<int>(n);
		for (int i = 1; i < n; i++){
			scanf("%d", &parent[i]);
			tree[parent[i]].push_back(i);
		}
		traversal(0, 0);
		for (int i = 0; i < m; i++){
			int c1, c2, d1, d2, ans = 0;
			scanf("%d %d", &c1, &c2);
			d1 = depth[c1];
			d2 = depth[c2];
			ans = d1 + d2;
			if (d1 < d2){
				swap(c1, c2);
				swap(d1, d2);
			}
			while (d1 > d2){
				c1 = parent[c1];
				d1 = depth[c1];
			}
			while (c1 != c2){
				c1 = parent[c1];
				c2 = parent[c2];
				d1 = depth[c1];
				d2 = depth[c2];
			}
			printf("%d\n", ans - d1 * 2);
		}
	}
}
