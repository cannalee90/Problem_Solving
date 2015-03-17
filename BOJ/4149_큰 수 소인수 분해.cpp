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
const long long  hash_value =  9223372036854775807;


typedef long long ll;
using namespace std;


bool P[100000001];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long a;
	cin >> a;
	while(!(a % 2))
	{
		a /= 2;
		cout << 2 << endl;
	}
	for(long long i = 3; i<=(int)sqrt(a * 1.0); i++)
	{
		if(i % 2 == 0) continue;
		if(P[i] == 0)
		{
			while(!(a % i))
			{
				a = a / i;
				cout << i << endl;
			}
			for(long long j = i; j<=100000001; j+=i)
			{
				P[j] = 1;
			}
		}
	}
	cout << a << endl;
}
