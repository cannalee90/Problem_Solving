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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	vector<pair<int, int> > data;
	int n;
	int t1,t2;
	cin >> n;

	vector<int> rank(n + 1, 1);

	for(int i = 0; i<n; i++)
	{
		cin >> t1 >> t2;
		data.push_back(make_pair(t1,t2));
	}

	for(int	i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(data[i].first > data[j].first && data[i].second > data[j].second)
			{
				rank[j]++;
			}
		}
	}

	for(int i = 0; i<n; i++)
	{
		cout << rank[i] << " ";
	}
	cout << endl;
}

