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

const int M = 100010;
int n, t;

int convert(int m, int d){
	int cnt = d;
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < m; i++)
		cnt += month[i];
	return cnt;
}

inline bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;

}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	vector<pair<int, int > > v(n);
	for (int i = 0; i < n; i++){
		int m, d;
		cin >> m >> d;
		v[i].first = convert(m, d);
		cin >> m >> d;
		v[i].second = convert(m, d);
	}
	sort(v.begin(), v.end(), cmp);
	int end = convert(3, 1), ans = 0, mmax = INT_MIN, maxp = -1;
	int m = n * 2;
	int i = 0;
	while(m--){
		if (v[i].first <= end){
			if (mmax < v[i].second){
				mmax = v[i].second;
				maxp = i;
			}
			i++;
		}
		else{
			ans++;
			end = v[maxp].second;
		}
		if (i == n) break;
	}
	if (end >= convert(12, 1)){
		cout << ans << endl;
		return 0;
	}
	ans++;
	end = v[maxp].second;
	if (end >= convert(12, 1)){
		cout << ans << endl;
		return 0;
	}
	else
		cout << "0" << endl;
}