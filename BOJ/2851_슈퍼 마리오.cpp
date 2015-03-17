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
	string d1;
	while(!cin.eof())
	{
		getline(cin, d1);
		for(int i = 0; i<d1.length(); i++)
		{
			if(d1[i] == 'B' && d1[i+1] == 'U' && d1[i+2] == 'G')
			{
				d1.replace(i, 3,"");
				i = -1;
			}
		}
		cout << d1 << endl;
	}
}
