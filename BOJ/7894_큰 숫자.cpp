#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>



typedef long long ll;
using namespace std;

long long  ans[10000010];


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	double sample = 0;
	cin >> t;
	for(int i= 1; i<=10000000; i++)
	{
		sample += log10((double)i);
		ans[i] = ceil(sample) + 1;

	}
	int n;
	while(cin >> n)
	{
		printf("%lld\n", ans[n]);
	}
}
