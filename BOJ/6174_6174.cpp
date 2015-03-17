#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include<cmath>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string big;
	string a;
	string small;
	int t1, t2;
	int n;
	int c = 0;
	cin >> n;
	for(int k = 0; k<n; k++)
	{
	cin >> a;

		c = 0;
		while(1)
		{
			t1 = 0; t2 =0;
			if(a == "6174") break;
			sort(a.begin(), a.end());
			small  = a;
			reverse(a.begin(), a.end());
			big = a;
			for(int i = 0; i<a.length(); i++)
			{
				t1 += ((double)small[i]-'0') * pow((double)10,3-i);
				t2 += ((double)big[i] - '0') * pow((double)10,3-i);
			}
			t2-= t1;
			a = "";
			while(t2 != 0)
			{
				a.push_back(t2 % 10+'0');
				t2 /= 10;
			}
			reverse(a.begin(), a.end());
			while(a.length() < 4)
			{
				a.insert(a.begin(),'0');
			}
			c ++;
		}
		cout << c << endl;
	}
}