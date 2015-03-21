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

vector<long long> tree;
vector<int> data;
vector<pair<int, int > > d1;
vector<pair<int, int> > d2;

int n, k, m;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		d1.push_back(make_pair(t1, i + 1));
	}
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		d2.push_back(make_pair(t1, i + 1));
	}
	sort(d1.begin(), d1.end());
	sort(d2.begin(), d2.end());
	
}