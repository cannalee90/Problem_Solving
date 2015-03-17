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

int t, n, m;
int check[21];
int tt[21];
int mmax;
int graph[21][21];

int checking(int idx)
{
	int c = 0;
	if(check[idx] == 0)
	{
		check[idx] = idx;
		c++;
	}
	for(int i =1; i<=n; i++)
	{
		if(graph[idx][i] == 1 && check[i] == 0)
		{
			check[i] = idx;
			c++;
		}
	}
	return c;
}
void unchecking(int idx)
{
	int c = 0;
	if(check[idx] == idx)
	{
		check[idx] = 0;
	}
	for(int i =1; i<=n; i++)
	{
		if(graph[idx][i] == 1 && check[i] == idx)
		{
			check[i] = 0;
		}
	}
}


void find(int idx, int cnt, int time)
{
	if(time > mmax) return;
	if(cnt == n)
	{
		if(mmax > time)
			mmax = time;
		return;
	}
	for(int i = idx + 1; i<=n; i++)
	{
		int c = checking(i);
		find(i,cnt + c, time + 1);
		unchecking(i);
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, t2;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<=n; j++)
			{
				graph[i][j] = 0;
			}
		}
		mmax = INF;
		for(int i = 0; i<n; i++)
		{
			check[i + 1] = 0;
			tt[i+ 1] = 0;
			cin >> t1;
			for(int j = 0; j<t1; j++)
			{
				cin >> t2;
				graph[i + 1][t2] = 1;
				graph[t2][i + 1] = 1;
			}
		}
		for(int i = 1; i<=n; i++)
		{
			int c = checking(i);
			find(i,c, 1);
			unchecking(i);
		}
		cout << mmax << endl;
	}
}


