#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 900000000

using namespace std;

typedef long long ll;



int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	ll begin, end;
	vector< pair<ll, ll> > table;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> begin >> end;
		table.push_back(make_pair(end, begin));
	}
	sort(table.begin(), table.end());
	begin = 0;
	int cnt = 0;
	for(int i = 0; i<table.size(); i++)
	{
		if(begin <= table[i].second)
		{
			begin = table[i].first;
			cnt++;
		}
	}
	cout << cnt << endl;
}
