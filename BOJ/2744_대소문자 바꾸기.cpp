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
	string a;
	cin >> a;
	int l = a.length();
	for(int i = 0; i<l; i++)
	{
		if(a.at(i) >= 'a' && a.at(i) <= 'z')
		{
			cout << (char)(a.at(i) - 32);
		}
		else if(a.at(i) >= 'A' && a.at(i) <= 'Z')
		{
			cout << (char)(a.at(i) + 32);
		}
	}
	cout << endl;
}