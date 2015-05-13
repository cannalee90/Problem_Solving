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
	const int M = 200010;
	int data[M], tree[M], lazy[M];

	void update(int node, int a, int b, int i, int j){
		if (lazy[node] != 0){
			if (a != b){
				lazy[node * 2] ++;
				lazy[node * 2 + 1]++;
				lazy[node * 2] %= 2;
				lazy[node * 2 + 1] %= 2;
				int amount = (b - a) + 1;
				int val = 0;
				if (lazy[node * 2] == 0)
					val += tree[node * 2];
				else
					val += (amount / 2) - tree[node * 2];
				if (lazy[node * 2 + 1] == 0)
					val += tree[node * 2 + 1];
				else
					val += (amount / 2) - tree[node * 2 + 1];
				tree[node] = val;
				lazy[node] = 0;

			}
			else{
				tree[node]++;
				tree[node] %= 2;
				lazy[node] = 0;
			}
		}
		if (a > j || b < i) return;
		if (a >= i && b <= j){		
			if (a != b){
				lazy[node * 2] ++;
				lazy[node * 2 + 1]++;
				lazy[node * 2] %= 2;
				lazy[node * 2 + 1] %= 2;

				int amount = (b - a) + 1;
				int val = 0;
				if (lazy[node * 2] == 0)
					val += tree[node * 2]; 
				else
					val += (amount / 2) - tree[node * 2];
				if (lazy[node * 2 + 1] == 0)
					val += tree[node * 2 + 1]; 
				else
					val += (amount / 2) - tree[node * 2 + 1];
				tree[node] = val;
			}
			else{
				tree[node]++;
				tree[node] %= 2;
			}
			return;
		}
		update(node * 2, a, (a + b) / 2, i, j);
		update(node * 2 + 1, (a + b) / 2 + 1, b, i, j);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	ll sum_query(int node, int a, int b, int i, int j){
		int ret = 0;
		if (lazy[node] != 0){
			if (a != b){
				lazy[node * 2] ++;
				lazy[node * 2 + 1]++;
				lazy[node * 2] %= 2;
				lazy[node * 2 + 1] %= 2;
				int amount = (b - a) + 1;
				int val = 0;
				if (lazy[node * 2] == 0)
					val += tree[node * 2];
				else
					val += (amount / 2) - tree[node * 2];
				if (lazy[node * 2 + 1] == 0)
					val += tree[node * 2 + 1];
				else
					val += (amount / 2) - tree[node * 2 + 1];
				tree[node] = val;
				lazy[node] = 0;
			}
			else{
				tree[node]++;
				tree[node] %= 2;
				lazy[node] = 0;
			}
		}
		if (a > j || b < i) return ret;
		if (a >= i && b <= j)
			return tree[node];
		ret += sum_query(node * 2, a, (a + b) / 2, i, j);
		ret += sum_query(node * 2 + 1, (a + b) / 2 + 1, b, i, j);
		return ret;
	}

	int get_idx(){
		int idx = 1;
		while (idx < n)
			idx *= 2;
		return idx;
	}

	int main()

	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w+", stdout);
	#endif
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++){
			int q, l, r;
			scanf("%d %d %d", &q, &l, &r);
			if (q == 1)
				printf("%d\n", sum_query(1, 1, get_idx(), l, r));
			if (q == 0)
				update(1, 1, get_idx(), l, r);
		}
	}