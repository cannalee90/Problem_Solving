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
	long long n, d2;
	long long max, min;
	cin >> n;
	vector< vector<long long> > d1(n);
	for(int i = 0; i<n; i++)
	{
		max = 0; 
		min = 11;
		for(int j = 0; j<5; j++)
		{
			cin >> d2;
			d1[i].push_back(d2);
		}
		sort(d1[i].begin(), d1[i].end());
		if(
		cout << d2 << endl;
	}
}
