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
	int t = 3;
	while(t--)
	{
		char t1;
		vector<int> data;
		for(int i = 0; i<8; i++)
		{
			cin >> t1;
			data.push_back(t1-'0');
		}
		int max = 1, maxp = 1;
		for(int i = 0; i<8; i++)
		{
			int lens = 1;
			for(int j = i + 1; j<8; j++)
			{
				if(data[i] == data[j]) lens++;
				else break;
			}
			if(lens > max) max = lens;
		}
		printf("%d\n", max);
	}
}
