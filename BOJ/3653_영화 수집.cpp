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
int t, n, m;

vector<int> tree;
vector<int> data;

int get_idx(){
	int idx = 1;
	while (idx < n + m)
		idx *= 2;
	return idx;
}

void maketree(){
	int idx = get_idx();
	tree = vector<int>(idx * 2 + 1);
	for (int i = idx + m; i < idx + m + n; i++)
		tree[i] = 1;
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		idx /= 2;
	}
}
void update(int idx){
	while (idx){
		tree[idx] ++;
		idx /= 2;
	}
}
void erase(int idx){
	while (idx){
		tree[idx] --;
		idx /= 2;
	}
}


int sum_query(int right){
	int left = get_idx();
	long long sum = 0;
	while (left <= right){
		if (left % 2 == 1)
			sum += tree[left++];
		if (right % 2 == 0)
			sum += tree[right--];
		left /= 2;
		right /= 2;
	}
	return sum - 1;
}



int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		vector<int> ans;
		vector<int> hash(n + 1);
		maketree();
		for (int i = 0; i < n; i++)
			hash[i + 1] = m + get_idx() + i;

		for (int i = 0; i < m; i++){
			int num;
			scanf("%d", &num);
			ans.push_back(sum_query(hash[num]));
			erase(hash[num]);
			update(m + get_idx() - i - 1);
			hash[num] = m + get_idx() - i - 1;
		}
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		puts("");
	}
}