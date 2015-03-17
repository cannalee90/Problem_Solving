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
	int n, m;
	cin >> n >> m;
	long long pl = n * m;
	long long re;
	for(int i = 0; i<4; i++)
	{
		cin >> re;
		re = pl- re;
		cout << re * -1 << " "; 
	}
	cin >> re;
	re = n * m - re;
	cout << re * -1 << endl; 
}
