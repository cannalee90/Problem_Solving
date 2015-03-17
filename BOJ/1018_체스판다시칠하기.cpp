#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

const int M = 100;

string m_1[8] = {"WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"};
string m_2[8] = {"BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"};
string map[M];

int check(int height, int width)
{
	int c1 = 0;
	int c2 = 0;
	for(int i = 0; i<8; i++)
	{


		for(int j = 0; j<8; j++)
		{
			if(m_1[i][j] != map[i+ height][j + width])
			{
				c1++;
			}
			if(m_2[i][j] != map[i + height][j + width ])
			{
				c2++;
			}
		}
	}
	if(c1 > c2) return c2;
	else return c1;
}

int main()
{
	int a;
	int n, m;
	int min = 999999999;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	for(int i =0; i<n; i++)
	{
		cin >> map[i];
		m = map[i].length();
	}
	for(int i = 0; i<n; i++)
	{
		if(i + 8 > n) break;
		for(int j = 0; j<m; j++)
		{
			if(j + 8 > m) break;
			a =check(i,j);
			if(min > a) min = a;
		}
	}
	cout << min << endl;
}