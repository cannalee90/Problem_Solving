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

vector<int> countChar(string name, vector<int> &check)
{
	for(int i = 0; i<name.length(); i++)
	{
		check[name[i] - 'A']++;
	}
	return check;
}

double calPercent(const vector<int> &check)
{
	int L = check['L' - 'A'];
	int O = check['O' - 'A'];
	int V = check['V' - 'A'];
	int E = check['E' - 'A'];
	return ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n, t;
	double max = -INF;
	string result;
	string name, t1;
	cin >> name;
	cin >> t;
	while(t--)
	{
		vector<int> check(28, 0);
		check = countChar(name, check);			
		cin >> t1;
		check = countChar(t1, check);
		int percent = calPercent(check);
		if(max < percent)	max = percent, result = t1;
		if(max == percent)
		{
			if(result > t1) result = t1;
		}
	}
	cout << result << endl;
}
