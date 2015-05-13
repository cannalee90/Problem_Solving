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

int n, m, t;
vector<ll>data;
vector<ll> tree;

int get_idx(){
	int idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}

void maketree(){
	int idx = get_idx();
	tree = vector<ll>(idx * 2 + 1);
	for (int i = 0; i < n; i++)
		tree[idx + i] = data[i];
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		idx /= 2;
	}
}

void update(int node, int a, int b, int i, int j, int c){
	if (a > b || a > j || b < i) return;
	if (a >= i && b <= j){
		tree[node] = c;
		return;
	}
	update(node * 2, a, (a + b) / 2, i, j, c);
	update(node * 2 + 1, (a + b) / 2 + 1, b, i, j, c);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum_query(int node, int a, int b, int i, int j){
	ll ret = 0;
	if (a > b || a > j || b < i) return ret;
	if (a >= i && b <= j)
		return tree[node];
	ret += sum_query(node * 2, a, (a + b) / 2, i, j);
	ret += sum_query(node * 2 + 1, (a + b) / 2 + 1, b, i, j);
	return ret;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	scanf("%d %d", &n, &m);
	data = vector<ll>(n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &data[i]);
	maketree();
	for (int i = 0; i < m; i++){
		ll x, y, idx, c;
		scanf("%lld %lld %lld %lld", &x, &y, &idx, &c);
		if (x > y) swap(x, y);
		printf("%lld\n", sum_query(1, 1, get_idx(), x, y));
		update(1, 1, get_idx(), idx, idx, c);
	}
}