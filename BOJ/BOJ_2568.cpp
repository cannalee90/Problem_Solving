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
#include <cmath>

typedef long long ll;
using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));

int get_idx(int p){
	int idx = 1;
	while(idx < p)
		idx *= 2;
	return idx;
}

pair<int, int > get_max(vector<pair<int, int > > &tree, int left, int right){
	pair<int, int> mmax(0, -1);
	while(left <= right){
		if(left % 2 == 1)
			mmax = max(mmax, tree[left++]);
		if(right % 2 == 0)
			mmax = max(mmax, tree[right--]);
		left /= 2;
		right /= 2;
	}
	return mmax;
}

void update(vector<pair<int, int > > &tree, int idx, int val, int path){
	tree[idx].first = val;
	tree[idx].second = path;
	idx/=2;
	while(idx){
		tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		idx/=2;
	}
}


int main()
{
	int n;
	pair<int, int > ans;
	scanf("%d", &n);
	vector<int> vi;
	vector<pair<int, int > > vp(n);
	for(int i = 0; i<n; i++) {
		scanf("%d %d", &vp[i].first, &vp[i].second);
		vi.pb(vp[i].second);
	}
	vi.pb(-987654321);
	vp.pb(make_pair(-987654321, 0));
	sort(vp.begin(), vp.end());
	sort(vi.begin(), vi.end());
	int ansp;
	int idx = get_idx(vi.size());
	vector<int> parent(n);
	vector<bool> visited(n);

	vector<pair<int, int > > tree(idx * 2, pair<int, int>(-987654321, -1));
	for(int i = 1; i<=n; i++){
		vector<int>::iterator itor = lower_bound(vi.begin(), vi.end(), vp[i].second);
		int right = itor - vi.begin() + idx - 1;
		pair<int, int > mmax = get_max(tree, idx, right);
		mmax.first += 1;
		update(tree, right + 1, mmax.first, i);
		if(ans < mmax){
			ans = mmax;
			ansp = i;
		}
		parent[i] = mmax.second;
	}
	visited[ansp] = true;
	visited[ans.second] = true;
	int p = parent[ans.second];
	while(p != -1){
		visited[p] = true;
		p = parent[p];
	}
	cout << n - ans.first << endl;
	for(int i = 1; i<=n; i++){
		if(!visited[i])
			cout << vp[i].first << endl;
	}
}

