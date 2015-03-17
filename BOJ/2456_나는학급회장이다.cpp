#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>
    
using namespace std;
  
int d1[4][4];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif

	int n, t1,t2,t3;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> t1 >> t2 >> t3;
		d1[1][0] += t1;
		d1[1][t1]++;
		d1[2][0] += t2;
		d1[2][t2]++;
		d1[3][0] += t3;
		d1[3][t3]++;
	}
	int max = d1[1][0]; int maxp = 0;
	for(int i = 1; i<=3; i++)
	{
		if(max < d1[i][0])
		{
			maxp = i;
			max = d1[i][0];
		}
	}
	for(int i = 1; i<=3; i++)
	{
		if(max == d1[i][0] && i != maxp)
		{
			if(d1[maxp][3] < d1[i][3])
			{
				maxp = i; continue;
			}
			else if(d1[maxp][3] == d1[i][3])
			{
				if(d1[maxp][2] < d1[i][2])
				{
					maxp = i; continue;
				}
				else if(d1[maxp][2] == d1[i][2])
				{
					if(d1[maxp][1] ==  d1[i][1])
					{
						cout << "0 " << max; return 0;
					}
				}
			}
		}
	}
	cout << maxp << " " << max;
}