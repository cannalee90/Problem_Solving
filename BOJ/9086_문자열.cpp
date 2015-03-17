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
	int t;
	cin >> t;
	while(t--)
	{
		string d1 = "";
		cin >> d1;
		if(d1.length() > 1)
		{
			cout << d1[0] << d1[d1.length() - 1] << endl;
		}
		else if(d1.length() == 1)
		{
			cout << d1.front() << d1.front() << endl;
		}
	}
}
