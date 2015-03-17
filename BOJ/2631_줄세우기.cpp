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

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t1;
	vector<int> d1;
	int mmax = 0;

	cin >> n;
	for(int i= 0; i<n; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	for(int i = 0; i<n; i++)
	{
		vector<int> check(n + 1,0);
		check[i] = 1;
		for(int j = i+1; j<n; j++)
		{
			int temp_max = 0;
			for(int k = j - 1; k>=i; k--)
			{
				if(d1[j] > d1[k])
					temp_max = max(temp_max, check[k]);
			}
			check[j] = temp_max + 1;
			mmax = max(mmax,check[j]);
		}
	}
	cout << n - mmax << endl;
}



