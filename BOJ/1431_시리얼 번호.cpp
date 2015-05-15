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

int n, m, t;

inline bool cmp(const pair<string, int>  &a, const pair<string , int >   &b){
	if (a.first.size() != b.first.size())
		return a.first.size() < b.first.size();
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	cin >> n;
	vector<pair<string, int> > data(n);
	for (int i = 0; i < n; i++){
		cin >> data[i].first;
		for (int j = 0; j < data[i].first.size(); j++){
			if (data[i].first[j] >= '0' && data[i].first[j] <= '9')
				data[i].second += data[i].first[j] - '0';
		}
	}
	sort(data.begin(), data.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << data[i].first << endl;
}

