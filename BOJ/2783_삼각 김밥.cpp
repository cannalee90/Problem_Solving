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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif	
	vector<pair<double, pair<int, int > > > data;
	pair<double, pair<int, int > > t;
	cin >> t.second.first;
	cin >> t.second.second;
	t.first = (double)t.second.first / t.second.second;
	data.push_back(t);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> t.second.first;
		cin >> t.second.second;
		t.first = (double)t.second.first / t.second.second;
		data.push_back(t);
	}
	sort(data.begin(), data.end());
	printf("%.2lf\n", data[0].first * 1000 + 0.00000001);
}