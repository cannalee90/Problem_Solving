#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;

int GCD(int a, int b)
{
	if(a > b) swap(a, b);
	while(a)
	{
		int temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n;
	cin >> t;
	while(t--)
	{
		int t1,t2, total = 0;
		cin >> n;
		vector<int> data;
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			data.push_back(t1);
		}
		for(int i = 0; i<n; i++)
		{
			for(int j = i + 1; j<n; j++)
			{
				total += GCD(data[i], data[j]);
			}
		}
		cout << total << endl;
	}
}
