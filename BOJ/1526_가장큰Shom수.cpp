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
	int n;
	cin >> n;
	for(int i = n; i>=0; i--)
	{
		int t1 =i;
		while(t1 >= 0)
		{
			if(t1 % 10 == 7 || t1 % 10 == 4)
			{
				if(t1 / 10 == 0)
				{
					cout << i<< endl;
					return 0;
				}
				else
				{
					t1 = t1 / 10;
				}
			}
			else
			{
				break;
			}
		}
	}
}