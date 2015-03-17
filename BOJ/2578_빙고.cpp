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

int bingocheck(vector<vector<int > > &map)
{
	int n = 5;
	int col[5] = {0};
	int row[5] = {0};
	int diameter[2] = {0};
	for(int i = 0; i<n; i++)
	{
		if(map[i][i] == -1)
			diameter[0] ++;
		if(map[i][4-i] == -1)
			diameter[1]++;
		for(int j = 0; j<n; j++)
		{
			if(map[i][j] == -1) col[i]++;
			if(map[j][i] == -1) row[i]++;
		}
	}
	int bingocnt = 0;
	for(int i = 0; i<2; i++)
	{
		if(diameter[i] == 5) bingocnt ++;
	}
	for(int i = 0; i<5; i++)
	{
		if(col[i] == 5) bingocnt++;
		if(row[i] == 5) bingocnt++;
	}
	return bingocnt;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	vector<vector<int > > map(6,vector<int>(6, 0));
	queue <int> caller;
	int n = 5;
	int t1;
	for(int i = 0; i<5; i++)
	{
		for(int j = 0; j<5; j++)
		{
			cin >> map[i][j];
		}
	}
	for(int i = 0; i<25; i++)
	{
		cin >> t1;
		caller.push(t1);
	}
	int cnt = 0;
	while(!caller.empty())
	{
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(caller.front() == map[i][j])
				{
					map[i][j] = -1;
				}
			}
		}
		cnt++;
		caller.pop();
		if(int a = bingocheck(map) >=3)
		{
			cout << cnt << endl;
			return 0;
		}
	}
}
