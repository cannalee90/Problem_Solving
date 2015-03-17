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
	for(int i = 0; i<n; i++)
	{
		bool check[11] = {0};
		string d1;
		int total = 0;
		cin >> d1;
		for(int i = 0; i<d1.length(); i++)
		{
			check[d1[i] -'0'] = true;
		}
		for(int i = 0; i<10; i++)
		{
			if(check[i]) total += 1;
		}
		cout << total << endl;
	}
}
