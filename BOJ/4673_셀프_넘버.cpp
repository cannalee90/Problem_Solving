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

int n, m;

int getN(int n)
{
	int t1 = n;
	int t2 = 0;
	while(t1)
	{
		t2 += (t1 % 10);
		t1 = t1 / 10;
	}
	return t2 + n;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	vector<int> check(20001);
	for(int i = 1; i<=10000; i++)
	{
		int number = i;
		while(1)
		{
			number = getN(number);
			check[number] = 1;
			if(number > 10000) break;
		}
	}
	for(int i = 1; i<=10000; i++)
	{
		if(!check[i]) printf("%d\n", i);
	}
}
