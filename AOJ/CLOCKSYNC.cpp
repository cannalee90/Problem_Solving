#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 12345678


typedef long long ll;
using namespace std;

int t, n, solution;
int cclock[16];
int check[10];

int isSync()
{
	int temp[16];
	int total =0;
	int mmove[10][5] = {{0, 1, 2, -1, -1}, 
						{3, 7, 9, 11, -1},
						{4, 10, 14, 15, -1},
						{0, 4, 5, 6, 7},
						{6, 7, 8, 10, 12},
						{0, 2, 14, 15, -1},
						{3, 14, 15, -1, -1},
						{4, 5, 7, 14, 15},
						{1, 2, 3, 4, 5},
						{3, 4, 5, 9, 13}};

	for(int i = 0; i<16; i++)
	{
		temp[i] = cclock[i];
	}
	for(int i = 0; i<10; i++)
	{
		total += check[i];
		for(int k = 0; k<check[i]; k++)
		{
			for(int j = 0; j<5; j++)
			{
				if(mmove[i][j] == -1) break;
				temp[mmove[i][j]] += 3;
				if(temp[mmove[i][j]] > 12) temp[mmove[i][j]] -= 12;
			}
		}
	}
	for(int i = 0; i<16; i++)
	{
		if(temp[i] != 12) return INF;
	}
	return total;
}

void cclockSync()
{
	while(1)
	{
		int a= isSync();
		if(a < solution)
		{
			solution = a;
		}
		check[0]++;
		for(int i = 0; i<=8; i++)
		{
			if(check[i] == 4)
			{
				check[i+1] ++;
				check[i] -= 4;
			}
			else
				break;
		}
		if(check[9] == 4)
			break;
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while(t--)
	{
		int t1;
		for(int i = 0; i<16; i++)
		{
			cin >> cclock[i];
		}
		solution = INF;
		for(int i = 0; i<10; i++)
			check[i] = 0;
		cclockSync();
		if(solution != INF)
			cout << solution << endl;
		else 
			cout << "-1" << endl;
	}
}
