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
	int n, m;
	int ans = 2;
	vector<int> vans;
	cin >> m;
	n = m;
	while (n){
		vector<int> series;
		series.push_back(m);
		series.push_back(n);
		int num = m - n;
		while (num >= 0){
			series.push_back(num);
			num = series[series.size() - 2] - series[series.size() - 1];
		}
		if (ans < series.size()){
			ans = series.size();
			vans = series;
		}
		n--;
	}
	cout << ans << endl;
	for (int i = 0; i < vans.size(); i++)
		cout << vans[i] << " ";
	cout << endl;
}
