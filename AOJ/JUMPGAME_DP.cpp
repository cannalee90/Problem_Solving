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
	int n, t;
	string wildcard;
	vector<string> result;
	cin >> t;
	while(t--)
	{
		cin >> n;	
		cin >> wildcard;
		vector<string> data(n + 1);
		for(int i = 0; i<n; i++)
		{
			cin >> data[i];
		}
		while(n--)
		{
			string word = data[n-1];
			int m = word.length(); 
			vector<int> DP(m + 1, m + 1);
			int index = 0;
			for(int i = 0; i<m; i++)
			{
				for(int j = 0; j<m; j++)
				{

				}
			}
		}
	}
}