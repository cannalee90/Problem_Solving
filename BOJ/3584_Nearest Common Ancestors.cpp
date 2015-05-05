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

vector < vector<int > > tree;
vector < int > depth;
vector <int> parent;

void traversal(int here, int d){
	depth[here] = d;
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
		int n;
		scanf("%d", &n);
		tree = vector<vector<int> >(n + 1);
		depth = vector<int>(n + 1);
		parent = vector<int>(n + 1);
		for (int i = 0; i < n - 1; i++){
			int p, c;
			scanf("%d %d", &p, &c);
			tree[p].push_back(c);
			parent[c] = p;
		}
		int root = 1;
		for (int i = 1; i <= n; i++){
			if (parent[i] == 0)
				root = i;
		}
		traversal(root, 0);
		int c1, c2, d1, d2;
		scanf("%d %d", &c1, &c2);
		d1 = depth[c1];
		d2 = depth[c2];
		int ans = d1 + d2;
		if (d2 > d1){
			swap(d2, d1);
			swap(c1, c2);
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
		printf("%d\n", c1);
	}
}