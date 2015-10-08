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

int n, m, test;
vector < pair<char, pair<int, int > > > res;
vector < pair<char, pair<int, int > > > res2;


bool cmp(pair<char, pair<int, int > >  &a, pair<char, pair<int, int > >  &b){
	return a.second.first < b.second.first;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	vector<int> vi(n);
	vector<int> vii(n);
	int ansp = 0;
	int cnt = 0;
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) cin >> vii[i];
	for (int i = 0; i < n ; i++){
		cnt++;
		bool isDone = true;
		res.clear();
		vi = vii;
		for (int j = i; j < n - 1; j++){
			if (vi[j + 1] - vi[j] > m){
				res.push_back(make_pair('-', make_pair(j + 2, abs(vi[j + 1] - (vi[j] + m)))));

				vi[j + 1] = vi[j] + m;
			}
			if (vi[j + 1] - vi[j] < m){
				res.push_back(make_pair('+', make_pair(j + 2, abs(vi[j + 1] - (vi[j] + m)))));

				vi[j + 1] = vi[j] + m;
			}
		}
		for (int j = i; j >= 1; j--){

			if (vi[j] - vi[j - 1] > m){
				res.push_back(make_pair('+', make_pair(j, abs(vi[j] - (vi[j - 1] + m)))));
				vi[j - 1] = vi[j] - m;
			}
			if (vi[j] - vi[j - 1] < m){
				res.push_back(make_pair('-', make_pair(j, abs(vi[j] - (vi[j - 1] + m)))));
				vi[j - 1] = vi[j] - m;
			}
		}
		for (int i = 0; i < vi.size(); i++)
		{
			if (vi[i] <= 0) {
				isDone = false;
				break;
			}
		}
		if (isDone && res.size() < ans){
			ans = res.size();
			res2 = res;
		}
	}
	cout << ans << endl;

	sort(res2.begin(), res2.end(), cmp);
	for (int i = 0; i < res2.size(); i++){
		cout << res2[i].first << " " << res2[i].second.first << " " << res2[i].second.second << endl;
	}
}