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

int n = 19;
int mmove[4][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 }, {1, -1}};
vector<vector<char> > baduk(25, vector<char>(25, '0'));


pair <int, int> ans;

int who_win(int height, int width)
{
	for (int i = 0; i < 4; i++)
	{
		int count = 0;
		for (int j = 0; j < 19; j++)
		{
			int compare_height = height  + (mmove[i][0] * j);
			int compare_width = width + (mmove[i][1] * j);
			if (compare_width >= 19 || compare_height >= 19 || compare_width <  0 || compare_height < 0) break;
			if (baduk[compare_height][compare_width] == baduk[height][width])
			{
				count++;
			}
			else break;
		}
		for (int j = 1; j < 19; j++)
		{
			int compare_height = height - (mmove[i][0] * j);
			int compare_width = width - (mmove[i][1] * j);
			if (compare_width >= 19 || compare_height >= 19 || compare_width <  0 || compare_height < 0) break;
			if (baduk[compare_height][compare_width] == baduk[height][width])
			{
				count++;
			}
			else break;
		}

		if (count == 5)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> baduk[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (baduk[i][j] != '0')
			{
				int result = who_win(i, j);
				if (result != -1)
				{
					if (result != 3)
					{
						cout << baduk[i][j] << endl;
						cout << i + 1 << " " << j + 1 << endl;
						return 0;
					}
					else
					{
						cout << baduk[i][j] << endl;
						cout << i + 5 << " " << j - 3 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "0" << endl;
}
