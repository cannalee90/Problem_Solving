#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

char d1[5];
vector<string> result;
int cnt;
char a[5];
char b[5];
char c[5];

void Makefour(int begin)
{
	int index;
	for(int i = 0; i<4; i++)
	{
		index = i + begin;
		if(index >= 4) index -= 4;
		b[i] = a[index];
	}
}

void Make(int begin)
{
	int index;
	for(int i = 0; i<4; i++)
	{
		index = i + begin;
		if(index >= 4) index -= 4;
		c[i] = a[index];
	}
}

void dfs(int index, int length)
{
	a[length-1] = index + '0';
	if(length == 4) 
	{
		for(int i = 1; i<=4; i++)
		{
			Makefour(i);
			for(int j = 0; j<4; j++)
			{
				if(a[j] > b[j]) return;
				if(b[j] > a[j]) break; 
			}
		}
		result.push_back(string(a));
		cnt++;
		return;
	}
	for(int i = 1; i<=9; i++)
	{
		dfs(i,length + 1);

	}
}


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	for(int i = 0; i<4; i++)
	{
		cin >> d1[i];
		a[i] = d1[i];
	}
	for(int i = 1; i<=4; i++)
	{
		Make(i);
		for(int j = 0; j<4; j++)
		{
			if(d1[j] > c[j]){d1[0] = c[0]; d1[1] = c[1]; d1[2] = c[2]; d1[3] = c[3]; break;}
			if(c[j] > d1[j]) break; 
		}
	}
	string b= string(d1);
	for(int i = 1; i<10; i++)
	{
		dfs(i,1);
	}
	for(int i = 0; i<cnt; i++)
	{
		if(result[i] == b){ 
			cout << i +1 << endl; 
		}
	}
}