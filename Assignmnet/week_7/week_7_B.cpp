#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;
map<string, int> hashing; //이름, node번호
vector<vector<int> > tree; //traversal을 위한 트리
vector<int> parent; //형제관계를 처리하기 위해서 parent배열을 사용
vector<int> depth;  // node의 깊이
vector<int> series; // 인덱스 트리를 만들기 위해서 필요한 배열(data)
vector<int> serial; // node의 번호를 쿼리번호 즉 
vector<int> indextree; //인덱스 트리용 배열


int n, cnt = 1, root = 1;
int series_cnt;

void input_modeling(){
	string str_1, str_2, str_3;
	int n_1, n_2, n_3;
	cin >> n;
	cin >> str_1;
	hashing[str_1] = cnt++;
	tree = vector<vector<int> >(n + 1);
	parent = vector<int>(n + 1);
	depth = vector<int>(n + 1);
	series = vector<int>((n + 1) * 2);
	serial = vector<int>(n + 1);

	for (int i = 0; i < n - 1; i++){
		cin >> str_1 >> str_2 >> str_3;
		n_1 = hashing[str_1];
		n_2 = cnt++;
		hashing[str_2] = n_2;
		if (str_3 == "부모"){
			tree[n_2].push_back(n_1);
			parent[n_1] = n_2;
			if (n_1 == root)
				root = n_2;
		}
		else if (str_3 == "형제"){
			tree[parent[n_1]].push_back(n_2);
			parent[n_2] = parent[n_1];
		}
		else if (str_3 == "자녀"){
			tree[n_1].push_back(n_2);
			parent[n_2] = n_1;
		}
	}
}
void traversal(int here, int height){
	depth[here] = height;
	serial[here] = series_cnt;
	series[series_cnt++] = here;
	for (int i = 0; i < tree[here].size(); i++){
		int there = tree[here][i];
		traversal(there, height + 1);
		serial[here] = series_cnt;
		series[series_cnt++] = here;
	}
}
int get_idx(){
	int idx = 1;
	while (idx < series_cnt)
		idx *= 2;
	return idx;
}
void make_tree(){
	int idx = get_idx();
	indextree.resize(idx * 2 + 1, INT_MAX);
	for (int i = idx; i < idx + series_cnt; i++){
		indextree[i] = depth[series[i - idx]];
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			indextree[i] = min(indextree[i * 2], indextree[i * 2 + 1]);
		}
		idx /= 2;
	}
}
int min_query(int left, int right){
	int mmin = INT_MAX;
	left += get_idx();
	right += get_idx();
	while (left <= right){
		if (left % 2 == 1){
			mmin = min(indextree[left++], mmin);
		}
		if (right % 2 == 0){
			mmin = min(indextree[right--], mmin);
		}
		left /= 2;
		right /= 2;
	}
	return mmin;
}
void output(){
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int left, right;
		string str_1, str_2;
		cin >> str_1 >> str_2;
		int n_1, n_2;
		n_1 = hashing[str_1];
		n_2 = hashing[str_2];
		left = serial[n_1];
		right = serial[n_2];
		if (left > right) 
			swap(left, right);
		cout << depth[n_1] + depth[n_2] - min_query(left, right) * 2 << endl;
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	input_modeling();
	traversal(root, 0);
	make_tree();
	output();
}