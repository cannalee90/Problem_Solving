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

long long n;

long long get_idx(){
	long long idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}

vector<long long> tree;

void make_tree(){
	long long idx = get_idx();
	tree.resize(idx * 2 + 1, 0);

}

void update(long long idx){
	idx = idx += get_idx();
	while (idx){
		tree[idx] ++;
		idx /= 2;
	}
}

long long sum_query(long long left){
	left += get_idx();
	long long right = get_idx() + n - 1;
	long long sum = 0;
	while (left <= right){
		if (left % 2 == 1)
			sum += tree[left++];
		if (right % 2 == 0)
			sum += tree[right--];
		left /= 2;
		right /= 2;
	}
	return sum;
}

int main()
{
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif	
	
	vector<long long> data;
	vector<long long> rank;
	cin >> n;
	for (long long i = 0; i < n; i++){
		long long t1;
		scanf("%lld", &t1);
		data.push_back(t1);
		rank.push_back(t1);
	}
	sort(rank.begin(), rank.end());
	make_tree();
	for (long long i = 0; i < n; i++){
		vector<long long>::iterator itor = lower_bound(rank.begin(), rank.end(), data[i]);
		printf("%d\n", sum_query(itor - rank.begin()) + 1);
		update(itor - rank.begin());
	}
}