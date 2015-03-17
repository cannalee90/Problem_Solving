#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
   
using namespace std;

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	long long n, m, t1;
	int cnt = 0;
	vector<long long> d1;
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> t1;
		d1.push_back(t1);
	}
	for(int i = 0; i<n; i++)
	{
		t1 = 0;
		for(int j = i; j<n; j++)
		{
			t1 += d1[j];
			if(t1 > m) break;
			else if(t1 == m) {cnt++; break;}
		}
	}
	cout << cnt << endl;
}
