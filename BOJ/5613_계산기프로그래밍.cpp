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

ll cal(char a, ll t1, ll result)
{
	if(a == '+') return result = result + t1;
	if(a == '-') return result = result - t1;
	if(a == '*') return result = result * t1;
	if(a == '/') return result = result / t1;
	if(a == '=') return result;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll result, t1;
	char a;
	cin >> result;
	cin >> a;
	while(a != '=')
	{
		cin >> t1;
		result = cal(a, t1, result);
		cin >> a;
	}
	cout << result;
}
