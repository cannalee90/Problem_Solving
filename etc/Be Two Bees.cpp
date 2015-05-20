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
	vector< pair<int, int > >  data;
	vector< pair<double, int > > ans;
	pair<int, int >  p;
	pair<double, int> q;
	ll n, total = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p.first;
		data.push_back(p);
		total += p.first;
	}
	for (int i = 0; i < n; i++)
		cin >> data[i].second;

	for (int i = 0; i < n; i++){
		q.first = ((double)(total)-data[i].first) / ((double)1 / data[i].second);
		q.second = i + 1;
		ans.push_back(q);
	}
	sort(ans.begin(), ans.end());
	cout << ans[0].second << " " << ans[1].second << endl;
}

