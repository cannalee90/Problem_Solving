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

const int M = 510;

int n,m;
int map[M][M];
int check[M];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1,t2;
	int here;
	int hereNF;
	int F = 0;
	cin >> n;
	cin >> m;
	for(int i = 0; i<m; i++)
	{
		cin >> t1 >> t2;
		map[t1][t2] = 1;
		map[t2][t1] = 1;
	}
	queue<int>vertex;
	queue<int>rela;
	vertex.push(1);
	rela.push(0);
	while(!vertex.empty())
	{
		here = vertex.front();
		hereNF = rela.front();
		check[here] = 1;
		for(int i = 1; i<=n; i++)
		{
			if(check[i] == 0 && map[here][i] == 1 && hereNF + 1 < 3)
			{
				vertex.push(i);
				rela.push(hereNF + 1);
			}
		}
		vertex.pop();
		rela.pop();
	}
	for(int i = 1; i<=n; i++)
	{
		if(check[i]) F++;
	}
	cout << F-1 << endl;
}