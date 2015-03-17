#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

int d1[5];
int d2[5];

int main()
{
	string n;
	int p, t;
	int totalm = 0;
	int total;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	for(int p = 0; p<t; p++)
	{
		for(int i = 0; i<4; i++)
		{
			d1[i] =0 ;
		}
		cin >> d2[0] >> d2[1] >> d2[2] >> d2[3];
		for(int i = 0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				if(d2[i] == d2[j]) d1[i]++;
			}
		}
		int maxp = 0;
		int max = d1[0];
		for(int i = 0; i<4; i++)
		{
			if(max < d1[i])
			{
				max = d1[i]; maxp = i;
			}
		}
		if(max == 4)
		{
			total =  d2[maxp] * 5000 + 50000;
		}
		if(max == 3)
		{
			total =  d2[maxp] * 1000 + 10000;
		}
		if(max == 2)
		{
			if(d1[0] == 2 && d1[1] == 2 && d1[2] == 2 && d1[3] == 2)
			{
				for(int i = 0; i<4; i++)
				{
					if(d2[i] != d2[0])
					{
						total =  2000 + d2[0] * 500 + d2[i] * 500;
						break;
					}
				}
			}
			else
			{
				total =  d2[maxp] * 100 + 1000;
			}
		}
		if(max == 1)
		{
			int m = d2[0];
			for(int i = 0; i<4; i++)
			{
				if(d2[i] > m) m = d2[i];
			}
			total = m * 100;
		}
		if(total > totalm) totalm = total;
	}
	cout << totalm << endl;
}