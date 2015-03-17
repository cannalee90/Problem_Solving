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

unsigned long long map[100];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	map[1] = 2;
	map[2] = 1;
	map[3] = 2;
	cin >> n;
	if(n == 1) 
	{
		cout << "1" << endl;
		return 0;
	}
	if(n <  4) 
	{
		cout << map[n] << endl;
		return 0;
	}
	for(int i = 4; i<= 95; i++)
	{
		for(int j = i -2; j>=1; j--)
		{
			map[i] += map[j];
		}
	}
	cout << map[n] << endl;
}