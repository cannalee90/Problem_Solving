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

vector<int> data;

int n, m, k;
int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	vector<int> res;
	for (int i = 0; i < n; i++){
		vector<int>::iterator itor = lower_bound(res.begin(), res.end(), data[i]);
		if (itor == res.end())
			res.push_back(data[i]);
		else
			*itor = data[i];
	}
	cout << n - res.size() << endl;
}
