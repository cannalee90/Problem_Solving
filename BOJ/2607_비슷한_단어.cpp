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

vector<int> counting(string a)
{
	vector<int> cnt(26, 0);
	for(int i = 0; i<a.length(); i++)
	{
		cnt[a[i] -'A'] ++;
	}
	return cnt;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int cnt =0;
	cin >> n;
	string a;
	cin >> a;
	vector<int> b = counting(a);
	while(n--)
	{
		string t1;
		cin >> t1;
		vector<int> t2 = counting(t1);
		int d = 0;
		for(int i = 0; i<26; i++)
		{
			if(abs(b[i] - t2[i]) >= 2) 
			{
				d += abs(b[i] - t2[i]);
			}
			else if(abs(t2[i] - b[i]) == 1)
			{
				d ++;
			}
		}
		if(d <= 1) cnt++;
		else if(d == 2 && a.length() == t1.length()) cnt++;
	}
	cout << cnt << endl;
}
