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
 
ll n;
vector<int> Num;
bool era[100000010];
vector<int> Prime;

 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int m;
	int max;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> m;
		Num.push_back(m);
	}
	max = Num[n-1];
	sort(Num.begin(), Num.end());
	for(int i = 1; i<=Num[0]; i++)
	{
		int d = 0;
		for(int j = 0; j<n; j++)
		{
			if(Num[j] % i != 0)
			{
				d = 1;

				break;
			}
		}
		if(d == 0)
			printf("%d\n", i);
	}
}