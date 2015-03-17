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
	string table[1001];
	table[1] = "SK";
	table[2] = "CY";
	table[3] = "SK";
	table[4] = "SK";
	for(int i = 5; i<=n; i++)
	{
		if(table[i - 1] == "CY" || table[i-3] == "CY" || table[i-4] =="CY")
		{
			table[i] = "SK";
		}
		else
		{
			table[i] = "CY";
		}
	}
	cout << table[n] << endl;
}