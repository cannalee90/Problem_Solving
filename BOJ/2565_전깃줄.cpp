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
	vector<pair<int, int> > temp;
	vector<int> data(n + 1);
	vector<int> index(n + 1);
	vector<int> result;
	vector<int> ans(n + 1, 0);
	for (int i = 0; i < n; i++){
		int t1, t2;
		cin >> t1 >> t2;
		temp.push_back(make_pair(t1, t2));
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; i++){
		data[i] = temp[i].second;
		index[i] = temp[i].first;
	}
	
	for (int i = 0; i <n; i++){
		vector<int>::iterator itor = lower_bound(result.begin(), result.end(), data[i]);
		if (itor == result.end()){
			result.push_back(data[i]);
		}
		else{
			ans[itor - result.begin()] = *itor;
			*itor = data[i];
		}
	}
	cout << n - result.size() << endl;
}
