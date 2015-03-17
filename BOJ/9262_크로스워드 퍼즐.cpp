#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int left_margin, right_margin, upper_margin, bottom_margin;
	char ans[50][50];
	cin >> n >> m;
	cin >> upper_margin >> left_margin >> right_margin >> bottom_margin;
	for (int i = 0; i < upper_margin + bottom_margin + n ; i++)
	{
		for (int j = 0; j < left_margin + right_margin + m ; j++)
		{
			if (!((i + j) % 2)) ans[i][j] = '#';
			else ans[i][j] = '.';

		}
	}
	char a;
	for (int i = upper_margin; i < upper_margin + n; i++)
	{
		for (int j = left_margin; j < left_margin + m; j++)
		{
			cin >> a;
			ans[i][j] = a;
		}
	}
	for (int i = 0; i < upper_margin + bottom_margin + n; i++)
	{
		for (int j = 0; j < left_margin + right_margin + m; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}

}