#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>   

using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int nl = 1;
	int total = 0;
	list <int> result;
	string d1;
	while(!cin.eof())
	{
		getline(cin, d1);
		for(int i = 0 ; i<d1.length(); i++)
		{
			if(d1[i] == 'F' && d1[i + 1] == 'B' && d1[i+ 2] == 'I')
			{
				result.push_back(nl);
				total ++;
				break;
			}
		}
		nl++;
	}
	if(total == 0) cout << "HE GOT AWAY!" << endl;
	else
	{
		for(int i = 0; i<total - 1; i++)
		{
			cout << result.front() <<  " ";
			result.pop_front();
		}
		cout << result.front();
	}
	cout << endl;
}
