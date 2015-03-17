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
	int n = 0;
	while(cin >> n)
	{
		if(n == -1) break;
		vector<int> data;
		for(int i = 1; i<=sqrt((double)n);i++)
		{
			if(n % i == 0){	data.push_back(i), data.push_back(n / i); }
		}
		sort(data.begin(), data.end());
		if(data.back() == n) data.pop_back();

		int total = 0;

		for(int i= 0; i<data.size(); i++)
		{
			total += data[i];
		}
		if(total == n)
		{
			printf("%d =", n);
			for(int i = 0; i<data.size() - 1; i++)
			{
				printf(" %d +", data[i]);
			}
			printf(" %d\n",data.back());
		}
		else
		{
			printf("%d is NOT perfect.\n", n);
		}
	}
}
