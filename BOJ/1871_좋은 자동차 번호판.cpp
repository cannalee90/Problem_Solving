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

int getN(int index, int d1)
{
	return d1 * pow((double)26, (double)index);
}

void initialize(string &d1, string &d2, long long &r1, long long &r2)
{
	d1 = "";
	d2 = "";
	r1 = 0;
	r2 = 0;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif


	int n;
	string d1, d2;
	long long r1,r2;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		initialize(d1, d2, r1,r2);
		cin >> d1;	
		for(int j = 0; j<3; j++)
		{
			r1 += getN(2 - j, (int)(d1[j] - 'A'));
		}
		for(int j = 4; j<d1.length(); j++)
		{
			d2 += d1[j];
		}
		r2 = stoi(d2);
		(abs(r2 - r1) <= 100) ? cout << "nice\n" : cout << "not nice\n";
	}
}
