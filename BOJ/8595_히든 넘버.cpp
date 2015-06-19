#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string str;
long long res = 0;
int main()
{
	scanf("%d", &n);
	cin >> str;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num *= (long long)10;
			num += (long long)(str[i] - '0');

		}
		else
		{
			res += (long long)num;
			num = 0;
		}
	}
	res += num;
	printf("%lld\n", res);
}