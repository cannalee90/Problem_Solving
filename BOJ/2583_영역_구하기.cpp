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

vector < vector<ll> > map(101, vector<ll> (101, 0));

int h, w, n,m;

bool Ispossible(int height, int width)
{
	if(height >= h || height < 0 || width >= w || width < 0) return 0;
	if(map[height][width] != 0) return 0;
	return 1;
}

int bfs(int height, int width)
{
	int max = 1;
	int cnt = 0;
	int mmove[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	queue <pair <ll, ll> > que;
	que.push(make_pair(height, width));
	map[height][width] = ++cnt;
	while(!que.empty())
	{
		height = que.front().first;
		width = que.front().second;
		for(int i = 0 ; i<4; i++)
		{
			if(Ispossible(mmove[i][0] + height, mmove[i][1] + width))
			{
				map[mmove[i][0] + height][mmove[i][1] + width] = ++cnt;
				que.push(make_pair(height + mmove[i][0], width + mmove[i][1]));
				if(cnt > max)
					max = cnt;
			}
		}
		que.pop();
	}
	return max;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll t1,t2,t3,t4;
	cin >> h >> w >> n;

	while(n--)
	{
		cin >> t1 >> t2 >> t3 >> t4;
		for(int i = t2; i<t4; i++)
		{
			for(int j = t1; j<t3; j++)
			{
				map[i][j] = -1;
			}
		}
	}
	int cnt = 0;
	vector<ll> result;
	for(int i = 0; i<h; i++)
	{
		for(int j = 0; j<w; j++)
		{
			if(map[i][j] == 0)
			{
				result.push_back(bfs(i,j));
				cnt++;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << cnt << endl;
	for(int i = 0; i<cnt; i++)
	{
		cout << result[i] << " ";
	}
}
