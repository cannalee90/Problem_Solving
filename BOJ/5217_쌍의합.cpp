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
		int n;
		cin >> n;
		printf("Pairs for %d: ", n);
		vector<pair<int, int> > ans;
		for (int i = 1; i <= 12; i++)
		{
			for (int j = i + 1; j <= 12; j++)
			{
				if (i + j == n) ans.push_back(make_pair(i, j));
			}
		}
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d %d", ans[i].first, ans[i].second);
			if (ans.size() - 1 != i) printf(", ");
		}
		cout << endl;
	}
}
