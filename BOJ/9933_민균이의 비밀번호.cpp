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
	vector<string> data;
	string a;
	for(int i = 0; i<n; i++)
	{
		cin >> a;
		data.push_back(a);
	}
	for(int i = 0 ;i <n; i++)
	{
		a = data[i];
		reverse(a.begin(), a.end());
		for(int j =0; j<n; j++)
		{
			if(a == data[j])
			{
				cout << a.length() << " " << a[a.length() / 2] << endl;
				return 0;
			}
		}
	}
}
