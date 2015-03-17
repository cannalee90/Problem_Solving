#include <iostream>
#include <utility>
#include <fstream>
#include <functional>
#include <limits.h>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

vector<vector<pair<int, int > > > graph;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	string alphabet[] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
	string data;
	string ans;
	cin >> n;
	cin >> data;
	for (int i = 0; i < n; i++)
	{
		string temp;
		for (int j = 0; j < 6; j++)
		{
			temp += data[i * 6 + j];
		}
		for (int j = 0; j <8; j++)
		{
			int number_of_differce= 0;
			for (int k = 0; k < 6; k++)
			{
				if (alphabet[j][k] != temp[k]) number_of_differce++;
			}
			if (number_of_differce <= 1)
			{
				ans += j + 'A';
			}
		}
		if (ans.size() - 1 != i)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}
