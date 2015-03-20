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

int n, m;
vector<int> data;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	vector<int> res;
	int n;
	cin >> n;
	data.resize(n + 1);
	for (int i = 0; i < n; i++){
		cin >> data[i];
	}
	for (int i = 0; i < n; i++){
		vector<int>::iterator itor = lower_bound(res.begin(), res.end(), data[i]);
		if (itor == res.end()){
			res.push_back(data[i]);
		}
		else
			*itor = data[i];
	}
	cout << n - res.size() << endl;	
}