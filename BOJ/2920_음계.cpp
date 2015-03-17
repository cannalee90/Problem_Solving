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
	int n = 8;
	vector<int> data;
	for (int i = 0; i < n; i++)
	{
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	bool ascending = true , descending = true;
	for (int i = 1; i < n; i++)
	{
		if (data[i] > data[i - 1]) descending = false;
		if (data[i] < data[i - 1]) ascending = false;
	}
	if (ascending) cout << "ascending" << endl;
	else if (descending) cout << "descending" << endl;
	else cout << "mixed" << endl;
}
