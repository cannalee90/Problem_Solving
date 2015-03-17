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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long n, t1;
	long long  d1[60];
	int countingMax  = 0;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> d1[i];
	}
	for(int i = 1; i<=n; i++)
	{
		int cnt = 0;
		double max = -999999999999999;
		double slope;
		for(int j = i+1; j<=n; j++)
		{
			slope = (double)(d1[j] - d1[i]) / (abs)(j - i);
			if(slope > max)
			{
				max = slope;
				cnt++;
			}
		}
		max = -9999999999999999;
		for(int j = i - 1; j>=1; j--)
		{
			slope = (double)(d1[j] - d1[i]) / (abs)(j - i);
			if(slope > max)
			{
				max = slope;
				cnt++;
			}
		}
		if(countingMax < cnt) 
		{
			countingMax = cnt;
		}
	}
	cout << countingMax << endl;
}