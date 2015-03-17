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

int t;
int n;

bool Ispossible(int height, int width)
{
	if(height > n || width > n) return 0;
	return 1;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<vector<int> > map(n + 1, vector<int>(n + 1,0));
		vector<vector<int> > check(n + 1, vector<int>(n + 1,0));

		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				cin >> map[i][j];
			}
		}
		queue<pair<int, int> > que;
		que.push(make_pair(1,1));

		int d = 0;

		while(!que.empty())
		{
			int height = que.front().first;
			int width = que.front().second;
			int distance = map[height][width];

			que.pop();
			
			if(Ispossible(height + distance, width) && check[height + distance][width] == 0)
			{
				if(height + distance ==  n && width == n)
				{
					d = 1;
					break;
				}
				check[height + distance][width] = 1;
				que.push(make_pair(height + distance, width));
			}

			if(Ispossible(height, width + distance) && check[height][width + distance] == 0)
			{
				if(height ==  n && width  + distance == n)
				{
					d = 1;
					break;
				}
				check[height][width + distance] = 1;
				que.push(make_pair(height, width + distance));
			}
		}
		if(d == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}