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

int check[30];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	char a[100];
	int cnt = 0;
	int cntp;
	cin >> a;
	for(int i = 0; i <strlen(a); i++)
	{
		check[a[i] - 'A']++;
	}
	for(int i = 0; i<26; i++)
	{
		if(strlen(a) % 2 == 0 && check[i] % 2 != 0){cout << "I'm Sorry Hansoo" << endl; return 0;}
		if(strlen(a) % 2 == 1 && check[i] % 2 != 0){cnt ++; cntp = i;}
	}
	if(cnt > 1) {cout << "I'm Sorry Hansoo" << endl; return 0;}
	else
	{
		for(int i = 0; i<26; i++)
		{
			for(int j = 0; j<check[i]/2; j++)
			{
				if(check[i] != 0)
					printf("%c",i+'A');
			}
		}
		if(strlen(a) %2 != 0) 
		{
			for(int j = 0; j<check[cntp]/2; j++)
			{
				printf("%c",cntp+'A');
			}
		}
		for(int i = 25; i>=0; i--)
		{
			for(int j = 0; j<check[i]/2; j++)
			{
				if(check[i] != 0)
					printf("%c",i+'A');
			}
		}
	}

}