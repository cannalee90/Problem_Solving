	#include <iostream>
	#include<iomanip>
	#include <fstream>
	#include <string>
	#include <string.h>
	#include <queue>
	#include <stdio.h>
	#include <algorithm>
	#include <vector>
	#include <stack>
   
	using namespace std;

	class tomato
	{
	public:
		int depth;
		int height;
		int width;
		int distance;
		tomato(int depth, int height, int width, int distance)
		{
			this->depth = depth;
			this->height = height;
			this->width = width;
			this->distance = distance;
		}
	};

	int n, m, d;
	int na;

	const int M = 110;
	int mmove[6][3] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,0,1},{0,-1,0}, {0,0,-1}};
	int map[M][M][M];
	int cashe[M][M][M];

	bool coor(int depth, int height, int width)
	{
		if(depth > d || depth < 1) return 1;
		if(height > n || height < 1) return 1;
		if(width > m || width < 1) return 1;
		return 0;
	}

	int main()	
	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		int a = 0;
		queue <tomato> que;
		cin >> m >> n >> d;
		for(int k = 1; k<=d; k++)
		{
			for(int i = 1; i<=n; i++)
			{
					for(int j = 1; j<=m; j++)
				{
					cin >> map[k][i][j];
					cashe[k][i][j] = M*M*M*M;
					if(map[k][i][j] == -1) 
					{
						na ++;
						cashe[k][i][j] = -1;
					}
					if(map[k][i][j] == 1)
					{
						cashe[k][i][j] = 1;
						que.push(tomato(k,i,j,0));
					}
					if(map[k][i][j] == 0)
						a++;
				}
			}
		}
		if(a == 0) {cout << "0" << endl; return 0;}
		int max = 0;
		int cnt = 0;
		while(!que.empty())
		{
			tomato here = que.front();
			for(int i = 0; i<6; i++)
			{
				if(coor(here.depth + mmove[i][0], here.height  + mmove[i][1], here.width + mmove[i][2])) continue;
				if(cashe[here.depth + mmove[i][0]][here.height + mmove[i][1] ][here.width + mmove[i][2]]  == -1 || cashe[here.depth + mmove[i][0]][here.height + mmove[i][1]][here.width+ mmove[i][2]]  <= here.distance + 1) continue;
				que.push(tomato(here.depth + mmove[i][0], here.height + mmove[i][1], here.width + mmove[i][2],here.distance + 1));
				cashe[here.depth + mmove[i][0]][here.height + mmove[i][1]][here.width + mmove[i][2]] = here.distance + 1;
				cnt ++;
				if(here.distance  + 1 > max ) max = here.distance + 1;
			}
		
			que.pop();
		}
			for(int k = 1; k<=d; k++)
			{
				for(int i = 1; i<=n; i++)
				{
					for(int j = 1; j<=m; j++)
					{
						if(cashe[k][i][j] == M*M*M*M) 
						{
							cout << "-1" <<endl;
							return 0;
						}
					}
				}
			}

		if(cnt == 0) 
		{
			cout << "0" << endl;
			return 0;
		}
		cout << max  << endl;
	}