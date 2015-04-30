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

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int ans = 0;
	int mmax = 0;
	cin >> n;
	vector < pair<int, int> > data;
	stack < pair<int, int > > st;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		data.push_back(make_pair(x, y));
		mmax = max(y, mmax);
	}
	sort(data.begin(), data.end());
	int idx = 0;
	int height = 0;
	int limit = 1001;
	for (int i = 1; i <= 1000; i++){
		if (i == data[idx].first){
			if (height < data[idx].second)
				height = data[idx].second;	
			idx++;

		}
		ans += height;
		if (height == mmax) {
			limit = i;
			break;
		}
	}
	idx = n - 1;
	height = 0;
	for (int i = 1000; i > limit; i--){
		if (i == data[idx].first){
			if (height < data[idx].second)
				height = data[idx].second;
			idx--;

		}
		ans += height;
	}
	cout << ans << endl;
}