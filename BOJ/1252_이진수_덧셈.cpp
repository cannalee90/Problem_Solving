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

char result[100];


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string a, b;
	int idx = 0;
	size_t pos;
	cin >> a;
	cin >> b;
	pos = a.find('1');
	if(pos >= a.length())
		a = '0';
	else
		a = a.substr(pos, a.length() - pos);
	pos = b.find('1');
	if(pos >= b.length())
		b = '0';
	else 
		b = b.substr(pos, b.length() - pos);
	if(a == "0" && b == "0")
	{
		cout << "0" << endl;
		return 0;
	}
	if(b.length() > a.length()) swap(a,b);
	while(b.length() != 0 && a.length() != 0)
	{
		if(result[idx] == 0)
			result[idx] += a[a.length() -1] + b[b.length() - 1] - '0';
		else
			result[idx] += a[a.length() -1] + b[b.length() - 1] - '0' -'0';
		if(result[idx] >= '2')
		{
			result[idx] -= 2;
			result[idx + 1] = '1';
		}
		a.pop_back();
		b.pop_back();
		idx++;
	}
	while(a.length() != 0)
	{
		if(result[idx] == 0)
			result[idx] += a[a.length() - 1];
		else
			result[idx] += a[a.length() - 1] - '0';
		if(result[idx] >= '2')
		{
			result[idx] -= 2;
			result[idx + 1] = '1';
		}
		a.pop_back();
		idx++;
	}
	int d = 0;
	for(int i = strlen(result) - 1; i>= 0; i--)
	{
		if(d == 0 && result[i] == '0') continue;
		printf("%c", result[i]);
		d = 1;
	}
	printf("\n");
}
