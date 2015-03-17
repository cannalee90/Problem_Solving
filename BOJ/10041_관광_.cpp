#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
    
using namespace std;
 
int mmove[6][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1}};
int n, m, visit;
int total;
int d1[1100][2]; 

 
bool coor(int height, int width)
{
    if(height > n || height < 1) return 1;
    if(width > m || width < 1) return 1;
    return 0;
}
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int nw, nh, tw, th;
	int total = 0;
    cin >> n;
    cin >> m;
    cin >> visit;
		cin >> d1[0][0];
		cin >> d1[0][1];
    for(int i = 1; i<visit; i++)
    {
		cin >> d1[i][0];
		cin >> d1[i][1];
		nh = d1[i][0];
		nw = d1[i][1];
		th = d1[i-1][0];
		tw = d1[i-1][1];
		while(1)
		{
			if(nw == tw && nh == th) break;
			total ++;
			if(nw == tw && nh > th)
			{
				nh--; continue;
			}
			if(nw == tw && nh < th)
			{
				nh++; continue;
			}
			if(nw > tw && nh == th)
			{
				nw--; continue;
			}
			if(nw < tw && nh == th)
			{
				nw++; continue;
			}
			if(nw < tw && nh < th)
			{
				nw++;
				nh++;
				continue;
			}
			if(nw > tw && nh > th)
			{
				nh--;
				nw--;
				continue;
			}
			if(nw > tw && nh < th)
			{
				nw--;
				continue;
			}
			if(nw < tw && nh > th)
			{
				nw ++;
				continue;
			}
		}
	}
	cout << total << endl;
}