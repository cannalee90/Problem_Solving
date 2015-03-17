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

int n, m, t, w, h;
int cnt;
int solution;
char map[31][30];
vector< pair <int, int> > coor;
int ssize;

void Fill(int height, int width, int k)
{
	if(k == 0)
	{
		map[height][width] = '0';
		map[height][width+1] = '0';
		map[height+1][width+1] = '0';
		return;
	}
	if(k == 1)
	{
		map[height][width] = '1';
		map[height][width+1] = '1';
		map[height+1][width] = '1';
		return;
	}
	if(k ==2)
	{
		map[height][width] = '2';
		map[height+1][width+1] = '2';
		map[height+1][width] = '2';
		return;
	}
	if(k == 3)
	{
		map[height][width] = '3';
		map[height+1][width-1] = '3';
		map[height+1][width] = '3';
		return;
	}
}
void Unfill(int height, int width, int k)
{
	if(k == 0)
	{
		map[height][width] = '.';
		map[height][width+1] = '.';
		map[height+1][width+1] = '.';
		return;
	}
	if(k == 1)
	{
		map[height][width] = '.';
		map[height][width+1] = '.';
		map[height+1][width] = '.';
		return;
	}
	if(k ==2)
	{
		map[height][width] = '.';
		map[height+1][width+1] = '.';
		map[height+1][width] = '.';
		return;
	}
	if(k == 3)
	{
		map[height][width] = '.';
		map[height+1][width-1] = '.';
		map[height+1][width] = '.';
		return;
	}
}
//0 天天  1  天天  2 |   3   |
//     |     |		 |天   天|x``x



bool isPossible(int height, int width, int k)
{
	if(k == 0)
	{
		if(width + 1 >= w || height + 1 >= h) return 0;
		if(map[height][width + 1] != '.' || map[height + 1][width + 1] != '.') return 0;
		return 1;
	}
	if(k == 1)

	{
		if(width + 1 >= w || height + 1 >= h) return 0;
		if(map[height + 1][width] != '.' || map[height][width + 1] != '.') return 0;
		return 1;
	}
	if(k == 2)
	{
		if(width + 1 >= w || height + 1 >= h) return 0;
		if(map[height + 1][width] != '.' || map[height + 1][width + 1] != '.') return 0;
		return 1;
	}
	if(k == 3)
	{
		if(width -1  < 0 || height + 1 >= h) return 0;
		if(map[height + 1][width] != '.' || map[height + 1][width - 1] != '.') return 0;
		return 1;
	}
}


void filling(int white, int idx)
{
	if(white == 0)
	{
		solution++;
		return;
	}
	int a = 0;
	for(int p = idx; p<ssize; p++)
	{
		int i = coor[p].first;
		int j = coor[p].second;
		if(map[i][j] == '.')
		{
			for(int k = 0; k<4; k++)
			{
				if(isPossible(i,j,k))
				{
					Fill(i,j,k);
					filling(white-3,p + 1);
					Unfill(i,j,k);
				}
			}
			return;
		}
	}
}


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	char a;
	cin >> t;
	while(t--)
	{
		int bh, bw;
		int white = 0;
		cin >> h >> w;
		int d = 0;
		for(int i = 0;i<h; i++)
		{
			for(int j = 0; j<w; j++)
			{
				cin >> a;
				map[i][j] = a;
				if(a == '.')
				{
					white++;
					coor.push_back(make_pair(i,j));
				}
			}
		}
		solution = 0;
		ssize = white;
		if(white % 3 != 0)
			cout << "-1" << endl;
		else
		{
			filling(white, 0);
			cout << solution << endl;	
		}
		for(int i= 0; i<white; i++)
		{
			coor.pop_back();
		}
	}
}
