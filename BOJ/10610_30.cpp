#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int sum = 0;
	string a;
	cin >> a;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i] - '0';
	}
	if (sum % 3 != 0 || a[a.size() - 1] != '0')
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << a << endl;
	}
}