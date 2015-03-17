#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
 
using namespace std;
 
int mmove[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int map[1010][1010];
 
bool coor(int height, int width)
{
    if(height < 1 || height > n) return 1;
    if(width < 1 || width > m) return 1;
    return 0;
}
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int h , w;
	int f;
    int cnt = 0;
    cin >> m >> n;
	cin >> f; 
    int number = 1;
    int height = 1, width = 1;
    map[height][width] = number++;
	if(f > n * m)
	{
		cout << "0" << endl;
		return 0;
	}
	if(f == 1)
	{
		cout << "1 1" << endl;
		return 0;
	}
    while(1)
    {
        for(int i = 0; i<n* m; i++)
        {
            if(number > n * m) break;
            if(coor(height + mmove[cnt][0],width + mmove[cnt][1])) continue;
            if(map[height + mmove[cnt][0]][width + mmove[cnt][1]] != 0) break;
            map[height + mmove[cnt][0]][width + mmove[cnt][1]] = number++;
            height = height + mmove[cnt][0];
            width = width + mmove[cnt][1];
        }
        if(number > n * m) break;
        cnt++;
        if(cnt == 4) cnt = 0;
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1;j<=m; j++)
        {
            if(f == map[i][j])
			{
				cout << j << " " << i << endl;
				return 0;
			}
        }
    }
}