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

int n, m;
string result;

bool iSprime(int num)
{
	for(int i = 2; i<num; i++)
	{
		if(num % i == 0)
			return 0;
	}
	return 1;
}

void make_series(int index, int cnt)
{
	result += (index + '0');
	if(cnt == n)
	{

	}
	for(int i = 0; i<10; i++)
	{
		string t1 = result;
		t1 += (i + '0');
		if(iSprime(stoi(t1)))
			make_series(i, cnt+1);
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	make_series(2, 1);
	make_series(3, 1);
	make_series(5, 1);
	make_series(7, 1);

}
