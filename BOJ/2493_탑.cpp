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
	cin >> n;
	vector<int> data;
	vector<int> set(n);
	for(int i = 1; i<=n; i++)
	{
		ll t1;
		scanf("%lld", &t1);
		data.push_back(t1);
	}
	ll mmax = 0;
	set[0] = -1;
	cout << "0 ";
	for(int i = 1; i<n; i++)
	{
		if(data[i-1] > data[i])
		{
			printf("%d ",i);
			set[i] = i-1;
		}
		else
		{
			int index = set[i-1];
			while(1)
			{
				if(index == -1)
				{
					printf("0 ");
					set[i] = -1;
					break;
				}
				if(data[index] > data[i])
				{
					printf("%d ",index + 1);
					set[i] = index;
					break;
				}
				else
				{
					index = set[index];
				}
			}
		}
	}
}
