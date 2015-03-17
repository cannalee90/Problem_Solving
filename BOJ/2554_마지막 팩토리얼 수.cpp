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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long result = 1;
	long long n;
	int digit;
	long long d1;
	unsigned long long d2 = 1;
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		d2 *= i;
		result *= i;
		d1 = i;
		digit = 0;
		while(d1 % 5 == 0){d1 = d1 / 5; digit ++;}
		digit = pow((double)10, digit);
		result = result / digit;
		d1 = i;
		digit = 1;
		result = result % 10000000;
	}
	cout << result % 100000 << endl;
}
