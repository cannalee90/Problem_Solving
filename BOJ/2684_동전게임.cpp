#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

string comp[] = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
int d1[10];

int main()
{
	int n;
	string a;
	string t1;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> a;
		for(int j = 0; j<a.length() - 2; j++)
		{
			t1 = a.substr(j,3);
			for(int k = 0; k<8; k++)
			{
				if(t1 == comp[k])
					d1[k]++;
			}
		}
		for(int k = 0; k<8; k++)
		{
			printf("%d ",d1[k]);
			d1[k] = 0;
		}
		cout << endl;
	}
}