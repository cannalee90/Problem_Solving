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
	vector<int>d1;
	int n, m;
	int t;
	int countx = 0;

	int cnt = 0;
	cin >> n;
	cin >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> t;
		d1.push_back(t);
	}
	while(countx < n)
	{
		cnt++;
		t = m;
		for(int i = 0; i< n; i++)
		{
			if(check[i] == 0 && t >= d1[i])
			{
				check[i] =1;
				countx++;
				t-= d1[i];
			}
			else if( t < d1[i]) break;
		}
	}
	cout << cnt;
}