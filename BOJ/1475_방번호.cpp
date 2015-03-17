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

int check[14];

int n, m;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string rN;
	cin >> rN;
	for(int i = 0; i<rN.length(); i++)
	{
		check[rN[i]-'0']++;
	}
	int max = 0;
	for(int i = 0; i<10; i++)
	{
		if(check[i] > max && i != 9 && i != 6)
			max = check[i];
		else if(i == 6 || i == 9)
		{
			if((check[6] + check[9]) /2 + ((check[6] + check[9])%2) > max)
				max = (check[6] + check[9]) /2 + ((check[6] + check[9])%2);
		}
	}
	cout << max << endl;
}
