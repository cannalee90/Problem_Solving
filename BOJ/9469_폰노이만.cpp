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
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		double d, a, b, f;
		cin >> n >> d >> a >> b >> f;
		printf("%d %.2lf\n",n, (d / (a + b)) * f);
	}
}
