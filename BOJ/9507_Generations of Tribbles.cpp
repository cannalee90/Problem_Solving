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
	int t;
	vector<unsigned long long> f;
	f.push_back(0);
	f.push_back(1);
	f.push_back(1);
	f.push_back(2);
	for(int i = 4; i<=68; i++)
	{
		f.push_back(f[i-1] + f[i-2] + f[i-3] + f[i-4]);
	}
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << f[n+1] << endl;
	}

}
