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


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1, t2;
	unsigned long long a = 0, b =0;
	cin >> a >> b;
	while(a != 0)
	{
		ll temp = b;
		b = a;
		a = temp % a;
	}
	for(int i = 0; i<b; i++)
	{
		printf("1");
	}
	cout << endl;
}
