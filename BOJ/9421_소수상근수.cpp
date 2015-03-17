#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#define INF 900000000


typedef long long ll;
using namespace std;

bool P[1000001];

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	vector<int> Prime;
	Prime.push_back(2);
	for(int i = 2; i<=1000000; i+=2) P[i] = 1;
	for(int i = 3; i<=1000000; i++)
	{
		if(!P[i])
		{
			Prime.push_back(i);
			for(int j = i; j<=1000000; j+=i)
			{
				P[j] = 1;
			}
		}
	}
	int idx = 0, ans = 0;
	cin >> n;
	for(int k = 0; k<Prime.size(); k++)
	{
		if(Prime[idx] > n) break;
		string Pri = to_string((long long)Prime[idx]);
		set<int> flag;
		set<int>::iterator itor;
		while(1)
		{
			int total = 0;
			for(int i = 0; i<Pri.size(); i++)
			{
				total += (Pri[i] -'0') * (Pri[i] - '0');
			}
			if(total == 1) 
			{
				printf("%d\n", Prime[idx]);
				ans++;
				break;
			}
			itor = flag.find(total);
			if(itor == flag.end())
				flag.insert(total);
			else
				break;
			Pri = to_string((long long)total);
		}
		idx++;
	}
}
