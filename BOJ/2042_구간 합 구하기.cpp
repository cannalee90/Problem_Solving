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
vector<long long> tree;

int n, m, k;
int get_idx(){
	int idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}
void make_tree(){
	int idx = get_idx();
	tree.resize(idx * 2 + 1, 0);
	for (int i = idx; i < idx + n; i++){
		tree[i] = data[i - idx];
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
		idx /= 2;
	}
}

void updating(int idx, int num){
	idx += get_idx()- 1;
	tree[idx] = num;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}

long long sum_query(int left, int right){
	long long ssum = 0;
	left += get_idx() - 1;
	right += get_idx() - 1;
	while (left <= right){
		if (left % 2 == 1){
			ssum += tree[left++];
		}
		if (right % 2 == 0){
			ssum += tree[right--];
		}
		left /= 2;
		right /= 2;
	}
	return ssum;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++){
		long long t1;
		scanf("%lld", &t1);
		data.push_back(t1);	
	}
	m += k;
	make_tree();
	for (int i = 0; i < m; i++){
		int query;
		cin >> query;
		if (query == 2){
			int left, right;
			cin >> left >> right;
			
			printf("%lld\n", sum_query(left, right));
		}
		else if (query == 1){
			int idx, num;
			cin >> idx >> num;

			updating(idx, num);
		}
	}
}