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

int n, m;

int LCM(int a, int b)
{
	if(a > b) swap(a, b);
	while(1)
	{
		if(a == 0)
			return b;
		else
		{
			int temp = a;
			a = b % a;
			b = temp;
		}
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1;
	vector<int> d1;
	cin >> n;
	for(int i= 0; i <n; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	t1 = LCM(d1[1]-d1[0] , d1[2] - d1[1]);
	for(int i = 2; i<n - 1; i++)
	{
		t1 = LCM(t1,d1[i+1] - d1[i]);
	}
	int total = 0;
	for(int i = 0; i<n - 1; i++)
	{
		total += ((d1[i+ 1] - d1[i]) / t1) - 1;
	}
	cout << total << endl;
	}
