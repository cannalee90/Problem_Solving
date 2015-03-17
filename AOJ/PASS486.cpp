#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF

typedef long long ll;
using namespace std;


const int MAX = 1000 * 1000 * 10;

int DP[MAX + 1];
bool P[MAX + 1];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	vector<int> Prime;
	Prime.push_back(2);
	for(int i = 3; i<=MAX; i++)
	{
		if( i % 2 != 0 &&!P[i])
		{
			Prime.push_back(i);
			if(i <= sqrt(MAX * 1.0))
			{
				for(int j = i; j<=MAX; j += i)
				{
					P[j] = 1;
				}
			}
		}
	}
	for(int i = 2; i<=MAX; i++)
	{
	}
}