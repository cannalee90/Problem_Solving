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
	int n;
	int cnt =0;
	cin >> n;
	for(int i = 1; i<=n/2; i++)
	{
		for(int j = i; j<=n - i; j++)
		{
			if(n - i - j < j) break;
			if(n - i - j  < i + j)
				cnt++;
		}
	}
	cout << cnt << endl;
}