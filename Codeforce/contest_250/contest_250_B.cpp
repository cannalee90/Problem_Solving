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

bool cmp(const pair<int, int> &a, pair <int, int> &b) {
	return a.first > b.first;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int sum;
	int limit;
	vector<pair<int, int > > v;
	cin >> sum >> limit;
	for (int i = 1; i <= limit; i++){
		for (int j = 1; j <= i;){
			if (i & j){
				v.push_back(make_pair(j, i));
				break;
			}
			else{
				j <<= 1;
			}
		}
	}
	sort(v.begin(), v.end(),cmp);
	int ans = 0;
	vector<int> res;
	for (int i = 0; i <v.size(); i++){
		if (sum - v[i].first >= 0){
			sum -= v[i].first;
			res.push_back(v[i].second);
			ans++;
		}
	}
	if (sum)
		cout << "-1";
	else{
		cout << ans << endl;
		for (int i = 0; i < ans; i++){
			cout << res[i] << " "; 
		}
	}
	cout << endl;
}
