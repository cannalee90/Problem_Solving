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
	long long n;
	int m;
	long long data;
	int cnt = 0;
	cin >> n;
	cin >> m;
	data = n;
	while(1)
	{
		n = data;
		n = n / 100;
		n = n * 100;
		n += cnt;
		if(n % m == 0) break;
		else cnt++;
	}
	if(cnt >= 10) printf("%d\n",cnt);
	if(cnt < 10) printf("0%d\n",cnt);
}