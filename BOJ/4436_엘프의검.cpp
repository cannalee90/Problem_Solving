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

bool check[14];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long n;
	while(1)
	{
		int cnt = 0;
		int c= 0 ;
		int series = 1;
		long long Number;
		cin >> n;
		if(cin.fail()) break;
		memset(check,0,11);
		while(1)
		{
			if(c == 10) break;
			Number = series++ * n;
			cnt++;
			while(1)
			{
				if(check[Number % 10] == false)
				{
					check[Number % 10] = true;
					c++;
				}
				if(Number / 10 == 0) break;
				else Number = Number / 10;
			}
		}
		cout << cnt << endl;
	}
}