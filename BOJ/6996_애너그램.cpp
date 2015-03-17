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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	string a, b;
	cin >> t;
	while(t--)
	{
		vector<int> ch1(200, 0);
		vector<int> ch2(200, 0);
		cin >> a >> b;
		if(a.length() == b.length())
		{
			for(int i = 0; i<a.length(); i++)
			{
				ch1[a[i]-'A']++;
				ch2[b[i]-'A']++;
			}
		}
		else
		{
			printf("%s & %s are NOT anagrams.\n", a.c_str(), b.c_str());
			continue;
		}
		if(ch1 == ch2)
		{
			printf("%s & %s are anagrams.\n", a.c_str(), b.c_str());
		}
		else
		{
			printf("%s & %s are NOT anagrams.\n", a.c_str(), b.c_str());
		}
	}
}
