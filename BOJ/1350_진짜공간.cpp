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
	int t, m, test;
	long long sizeofcluster;
	long long sizeoffile[1010];
	unsigned long long total = 0;
	cin >> test;
	for(int i = 0; i<test; i++)
	{
		cin >> sizeoffile[i];
	}
	cin >> sizeofcluster;
	for(int i = 0; i<test; i++)
	{
		int a = sizeoffile[i] % sizeofcluster;
		if(a == 0)
		{
			total +=  (int)sizeoffile[i] / sizeofcluster * sizeofcluster;
		}
		else
		{
			int temp = (int)((double)(sizeoffile[i] / sizeofcluster) + (double)1);
			total +=  (int)(temp* sizeofcluster);
		}
	}
	cout << total << endl;
}