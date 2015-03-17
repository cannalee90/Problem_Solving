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

void input(int const n, vector<int> &d1)
{
	int temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		d1.push_back(temp);
	}
}

int getMid(int const n, vector<int> &d1)
{
	double sum = 0 ;
	for(int i = 0; i<n; i++)
	{
		sum += d1[i];
	}
	return (int)((sum / (double)n)  + (double)0.5);
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	int m;
	cin >> n;
	for(int i = 0 ; i<n; i++)
	{
		cin >> m;
		vector<int> d1;
		input(m, d1);
		sort(d1.begin(), d1.end());
		int point = getMid(m, d1);
		cout << abs(d1[0] - point) * 2 + abs(d1[m - 1] - point) * 2 << endl;
	}
}
	