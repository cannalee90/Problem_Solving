#include <iostream>
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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int sum = 0;
	vector<int> data;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int t1;
		cin >> t1;
		data.push_back(t1);
		if (i < m) sum += data[i];
	}
	int mmax = sum;
	for (int i = m; i < n; i++)
	{
		sum += data[i] - data[i - m];
		mmax = max(mmax, sum);
	}
	cout << mmax << endl;
}