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


typedef long long ll;
using namespace std;

int n, m, t;
int solution;
int check[15];
int r;

void Picnic(vector< pair<int, int> > map, int counting, int idx)
{
	if(counting == n / 2)
	{
		solution ++;
		return;
	}
	for(int i = idx + 1; i<m + r; i++)
	{
		if(check[map[i].first] == 0 && check[map[i].second] == 0)
		{
			counting++; check[map[i].first] = counting; check[map[i].second] = counting;
			Picnic(map, counting, i);
			counting--; check[map[i].first] = 0; check[map[i].second] = 0;
		}
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1,t2;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		r = 0;
		vector< pair<int, int> > map;
		for(int i = 0; i<n; i++)
		{
			check[i] = 0;
		}
		for(int i = 0; i<m; i++)
		{
			cin >> t1 >> t2;
			if(t1 > t2)
				swap(t1, t2);
			map.push_back(make_pair(t1, t2));
		}
		sort(map.begin(), map.end());
		solution = 0;
		Picnic(map, 0, -1);
		cout << solution << endl;
	}
}
