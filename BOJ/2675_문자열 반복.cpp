#include <iostream>
#include <utility>
#include <fstream>
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

vector<vector<char> > data;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int r;
		string data;
		cin >> r >> data;
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < r; j++)
			{
				cout << data[i];
			}
		}
		cout << endl;
	}
}
