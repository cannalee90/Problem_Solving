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
	double c, a, b, d;
	double r1, r2;
	cin >> c >> a >> b;
	c = c * c;
	d = (b / a) * (b / a) + 1;
	r1 = c / d;
	r2 = c - r1;
	printf("%d %d\n", (int)sqrt(r1), (int)sqrt(r2));
}
