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
	int test,n;
	int temp;
	vector<int> d1;
	cin >> test;
	for(int t = 0; t<test; t++)
	{
		long long total = 0;
		cin >> n;
		vector<int> d1;
		for(int i = 0; i<n; i++)
		{
			cin >> temp;
			d1.push_back(temp);
		}
		sort(d1.begin(), d1.end());
		d1[1] = d1[0] + d1[1];
		total += d1[1];
		d1.erase(d1.begin());
		while(1)
		{
			if(d1.size() == 1) break;
			int min = 99999999999;
			int min1 = 0;
			int min2;
			for(int i = 0; i<d1.size(); i++)
			{
				for(int j = i + 1; j<d1.size(); j++)
				{
					if(min > d1[i] + d1[j])
					{
						min1 = i;
						min2 = j;
						min = d1[min1] + d1[min2];
					}
				}
			}
			d1[min1] = d1[min1] + d1[min2];
			total += d1[min1];
			d1.erase(d1.begin() + min2);
		}
		cout << total << endl;
	}
}