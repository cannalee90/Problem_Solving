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
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
