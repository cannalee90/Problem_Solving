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

int map[1010][1010];
int m;
int result[1010];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int NT, n;
	int cnt = 0;
	n = 1000;
	for(int p = 1; p<=n; p++)
	{
		for(int i = 1; i<=p; i++)
		{
			for(int j = 1; j<i; j++)
			{
				if(map[i][j] == 0)
				{
					cnt ++;
					int k = 1;
					while(1)
					{
						if(i * k > n || j * k > n) break;
						else
						{
							map[i*k][j * k] = 1;
							k++;
						}
					}
				}
			}
		}
		result[p] = (cnt*2) + 3;
	}
	cin >> NT;
	for(int i = 0; i<NT; i++)
	{
		cin >> n;
		printf("%d\n",result[n]);
	}
}

