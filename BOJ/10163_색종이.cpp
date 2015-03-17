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

int n;
vector<vector<int> > map;

bool Ispossible(int height, int width, int color)
{
	if(height > 100 || width > 100 || height < 0 || width < 0 || map[height][width] != color) return 0;
	return 1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	cin >> n;
	int t1, t2, t3, t4;
	map.resize(101, vector<int>(101, 0));
	vector<int> result(n, 0);
	for(int i = 0; i<n; i++)
	{
		cin >> t1 >> t2 >> t3 >> t4;
		for(int j = t2; j<t2 + t4; j++)
		{
			for(int k = t1; k<t1 + t3; k++)
			{
				map[j][k] = i + 1;
			}
		}
	}
	for(int i = 0; i<=100; i++)
	{
		for(int j = 0; j<=100; j++)
		{
			if(map[i][j] != 0)
			{
				int cnt = 1, color = map[i][j];
				queue<pair<int, int> > que;
				que.push(make_pair(i,j));
				map[i][j] = 0;
				while(!que.empty())
				{
					int height = que.front().first, width = que.front().second;
					que.pop();
					for(int k = 0; k<4; k++)
					{
						height += mmove[k][0], width += mmove[k][1];
						if(Ispossible(height, width, color))
						{
							cnt++;
							map[height][width] = 0;
							que.push(make_pair(height, width));
						}
					}
				}
				result[color - 1] += cnt;
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		cout << result[i] << endl;
	}
}
