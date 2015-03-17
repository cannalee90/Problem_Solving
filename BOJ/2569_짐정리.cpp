#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long n, m, t1;
	long long total = 0;
	long long mmin = 9999999;
	cin >> n;
	vector<long long> unsorted;
	vector<long long> sorted;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		unsorted.push_back(t1);
		sorted.push_back(t1);

	}
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i <n; i++)
	{
		if(sorted[i] != unsorted[i])
			if(mmin > sorted[i]) mmin = sorted[i];
	}
	for(int i = 0; i<n; i++)
	{
		if(sorted[i] != unsorted[i] && mmin != sorted[i])
			total += sorted[i] + mmin;
	}
	cout << total << endl;
}
