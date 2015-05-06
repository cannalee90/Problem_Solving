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
#include <functional>

typedef long long ll;
using namespace std;

vector<ll > tree;
vector<ll > lazy;
vector<ll> data;

int n;

int get_idx(){
	int idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}

void maketree(){
	int idx = get_idx();
	tree = vector<ll>(idx * 2 + 1, 0);
	lazy = vector<ll>(idx * 2 + 1, 0);	
	for (int i = 0; i < n; i++)
		tree[idx + i] = data[i];
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		idx /= 2;
	}
}

void update(int node, int left, int right, int i, int j, int value){
	if (lazy[node] != 0){
		if (left != right){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += (right - left + 1) * lazy[node];
		lazy[node] = 0;
	}

	if (left > right || left > j || right < i)
		return;
	if (left >= i && right <= j){
		tree[node] += (value) * (right - left + 1);
		if (left != right){
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	update(node * 2, left, (left + right) / 2, i, j, value);
	update(node * 2 + 1, (left + right) / 2 + 1, right, i, j, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum_query(int node, int left, int  right, int  i, int j){
	ll ret = 0;
	if (lazy[node] != 0){
		if (left != right){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += (right - left + 1) * lazy[node];
		lazy[node] = 0;
	}
	if (left > right || left > j || right < i)
		return 0;
	if (left >= i && right <= j){
		return tree[node];
	}

	ret += sum_query(node * 2, left, (left + right) / 2 , i, j);
	ret += sum_query(node * 2 + 1, (left + right) / 2 + 1, right, i, j);
	return ret;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int m;
	scanf("%d %d", &n, &m);
	data = vector<ll>(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	maketree();
	for (int i = 0; i < m; i++){
		char q;
		ll a, b, v;
		cin >> q;
		if (q == 'Q'){
			cin >> a >> b;
			cout << sum_query(1, 1, get_idx(), a, b) << endl;
		}
		else{
			cin >> a >> b >> v;
			update(1, 1, get_idx(), a, b, v);
		}
	}
}