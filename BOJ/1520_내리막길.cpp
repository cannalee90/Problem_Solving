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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		cout << "Distances: ";
		for (int i = 0; i < a.size(); i++)
		{
			if (b[i] >= a[i])
			{
				printf("%d ", b[i] - a[i]);
			}
			else
			{
				printf("%d ", b[i] + 26 - a[i]);
			}
		}
		printf("\n");
	}
}