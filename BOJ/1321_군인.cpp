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

ll leaf, num;

ll get_idx(ll p){
	ll idx = 1;
	while (idx < p) idx *= 2;
	return idx;
}

void update(vector<ll> &tree, ll idx, ll val){
	tree[idx] += val;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

void query(vector<ll> &tree, ll node, ll mmin, ll mmax, ll val){
	if (val < mmin || val > mmax) return;
	if (node >= leaf && node < leaf * 2 && val >= mmin && val <= mmax){
		num = node - leaf;
		return;
	}
	if (node >= leaf * 2) return;
	query(tree, node * 2, mmin, mmin + tree[node * 2], val);
	query(tree, node * 2 + 1, mmin + tree[node * 2] + 1, mmax, val);
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n, m;
	ll sum = 0;
	scanf("%lld", &n);
	ll idx = get_idx(n);
	vector<ll> tree(idx * 2);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &tree[i + idx]);
		sum += tree[i + idx];
	}
	idx /= 2;
	while (idx){
		for (ll i = idx; i<idx * 2; i++)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		idx /= 2;
	}
	scanf("%lld", &m);
	leaf = get_idx(n);
	for (ll i = 0; i < m; i++){
		ll q, loc, val;
		scanf("%lld", &q);
		if (q == 1){
			scanf("%lld %lld", &loc, &val);
			update(tree, leaf + loc - 1, val);
		}
		if (q == 2){
			scanf("%lld", &val);
			query(tree, 1, 0, tree[1], val);
			printf("%lld\n", num + 1);
		}
	}
}