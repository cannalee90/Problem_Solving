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
	long long total = 0;
	for(int i = 0; i<10000; i++)
	{
		for(int j =0; i<10000; j++)
		{
			total = total += 1;
		}
	}
	cout << total;
}