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
	int test;
	unsigned long long n,m;
	while(1)
	{
		unsigned long long result = 1;
		unsigned long long d1 = 1;
		unsigned long long t3;
		cin >> n >> m;
		if(n == m && n == 0) break;
		if(n - m < m) t3 = n - m;
		else t3 = m;
		while(t3)
		{
			t3--;
			result *= n--;
			result /= d1++;
		}
		cout << result << endl;
	}
}