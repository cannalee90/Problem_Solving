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

const int M = 110;

int button[M];
int n;

void change(int j)
{
	if(button[j] == 0) button[j] = 1;
	else if(button[j] == 1) button[j] = 0;
}

bool Ispossible(int j, int number)
{
	if(number + j > n || number - j < 1) return 1;
	for(int i = 1; i<=j; i++)
	{
		if(button[number + i ] != button[number - i]) return 1;
	}
	return 0;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int m;
	int gender, number;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> button[i];
	}
	cin >> m;
	for(int j = 1; j<=m; j++)
	{
		cin >> gender >> number;
		if(gender == 1)
		{
			for(int j = number; j<=n; j += number)
			{
				change(j);
			}
		}
		if(gender == 2)
		{
			int limit;
			for(int j = 0; j<=n; j++)
			{
				if(Ispossible(j, number)){limit = j; break;}
			}
			change(number);
			for(int j = 1; j<limit; j++)
			{
				change(number + j);
				change(number - j);
			}
		}
	}
	int cnt = 1;
	while(cnt < n)
	{
		cout << button[cnt++] << " ";
		if((cnt - 1) % 20 == 0) cout << endl;
	}
	cout << button[cnt] << endl;
}