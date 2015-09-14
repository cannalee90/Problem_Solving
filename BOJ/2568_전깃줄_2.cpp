#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int mmax = INT_MIN;
	cin >> n;
	vector<int> data(501, 0);
	vector<int> rdata;
	vector<int> result;
	vector<int> parent(501, -1);
	for (int i = 0; i < n; i++){
		int t1, t2;
		mmax = max(t1, mmax);
		cin >> t1 >> t2;
		data[t1] = t2;
	}
	int total = 0;
	int last = -1;
	vector<int> ans;
	vector<int> idx;
	last = 0;
	for (int i = 0; i <= mmax; i++){
		if (data[i] != 0)
			rdata.push_back(data[i]);
	}
	result.push_back(rdata[0]);
	idx.push_back(-1);
	for (int i = 1; i < rdata.size(); i++){
		vector<int>::iterator itor = lower_bound(result.begin(), result.end(), rdata[i]);
		if (itor == result.end()){
			parent[i] = idx[idx.size() - 1];
			result.push_back(rdata[i]);
			idx.push_back(i);
		}
		else{
			*itor = rdata[i];
			parent[i] = idx[itor - result.begin()];
		}
	}
}
