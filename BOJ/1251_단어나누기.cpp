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

string a;
string b;
string c;
string d;
vector<string> result;
int cnt;

void bfs(int begin, int index, int compound)
{
	if(compound == 2)
	{
		int l= 0;
		char b[50] = {0};
		char c[50] = {0};
		char d[50] = {0};
		for(int i = 0; i<begin; i++)
		{
			b[l++] = a[i];
		}
		l  = 0;
		for(int i = begin; i<index; i++)
		{
			c[l++] = a[i];
		}
		l = 0;
		for(int i = index; i<a.length(); i++)
		{
			d[l++] = a[i];
		}
		reverse(b,b+begin);
		reverse(c,c+(index- begin));
		reverse(d,d+a.length() - index);
		result.push_back(string(b) + string(c) + string(d));
		return;
	}
	for(int i = begin; i<a.length(); i++)
	{
		if(i + 1 < a.length())
			bfs(begin, i + 1,  compound + 1);
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> a;
	for(int i = 1; i<a.length(); i++)
	{
		bfs(i, i, 1);
	}
	sort(result.begin(), result.end());
	cout << result[0] << endl;
}