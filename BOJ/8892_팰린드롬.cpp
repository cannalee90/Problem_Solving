#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

string a[120];

int compact(int i, int j)
{
	int cnt = 0;
	int length = a[j].length();
	string b;
	b = a[i];
	while(cnt < length)
	{
		b.push_back(a[j][cnt++]);
	}
	for(int index = 0; index<b.length(); index++)
	{
		if(index == b.length() - 1 - index)
			break;
		if(b[index] != b[b.length() - 1 - index])
			return 0;
	}
	cout << b << endl;
	return 1;
}
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int c;
	int t, n, data;
	cin >> t;
	for(int test = 0; test < t; test++)
	{
		cin >> n;
		for(int i = 0; i<n; i++)
		{
			cin >> a[i];
		}
		c = 0;
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(i == j) continue;
				if(compact(i,j))
				{
					c = 1;
					break;
				}
			}
			if(c == 1) break;
		}
		if(c == 0) cout << "0" << endl;
	}
}