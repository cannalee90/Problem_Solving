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

int n, m;
vector<int> d1;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int  max = 0;
	int maxp;
	cin >> n >> m;
	unsigned long long t1;
	d1.push_back(0);
	for(int i = 0; i<m; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	sort(d1.begin(), d1.end());
	for(int i = 1; i<=m; i++)
	{
		if(m - i  + 1 < n) 
			t1 =( m - i + 1) * d1[i];
		else
			t1 = n * d1[i];
		if(t1 > max)
		{
			maxp  = i;
			max = t1;
		}
		
	}
	cout << d1[maxp] << " "<< max << endl;
}