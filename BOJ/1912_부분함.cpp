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
	int t1;
	vector<long long> d1;
	cin >> n;
	vector<long long> d2(n);
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	d2[0] = d1[0];
	for(int j = 1; j<n; j++)
	{
		if(d2[j - 1] + d1[j] > d1[j]) d2[j] = d2[j - 1] + d1[j];
		else d2[j] = d1[j];
	}
	long long max = d2[0];
	for(int i = 0; i<n; i++)
	{
		if(max < d2[i]) max = d2[i];
	}
	cout << max << endl;
}