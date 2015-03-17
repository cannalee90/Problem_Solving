#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

vector<int> result;

void eight(char a)
{
	int n = a - '0';
	int d = 4;
	while(d != 0)
	{
		result.push_back(n/ d);
		n = n % d;
		d = d / 2;
	}
}
int main()
{
	string n;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for(int i = 0; i<n.length(); i++)
	{
		eight(n[i]);
	}
	int d = 0;
	for(int i = 0; i<result.size(); i++)
	{
		if(d == 0 && result[i] == 0) continue;
		else {cout << result[i]; d = 1;}
	}
}