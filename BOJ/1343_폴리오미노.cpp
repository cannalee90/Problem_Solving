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
string result;
string r2;

string t[2] = {"AAAA", "BB"};


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> result;
	int index = 0;
	while(index < result.length())
	{
		int d = 0;
		if(result[index] == '.')
		{
			index++;
			continue;
		}
		for(int i = 0; i<2; i++)
		{
			int p = 0;
			for(int j = index; j<index + t[i].length(); j++)
			{
				if(j >= result.length() || result[j] == '.')
				{
					p = 1;
					break;
				}
			}
			if(p == 0)
			{
				result.replace(index,t[i].length(),t[i]);
				index += t[i].length();
				d = 1;
				break;
			}
		}
		if(d == 0)
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	cout << result << endl;
}
