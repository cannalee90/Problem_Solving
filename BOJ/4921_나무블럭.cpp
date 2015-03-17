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
	string data;
	int cnt = 1;
	while (cin >> data)
	{
		bool flag = 0;
		if (data == "0") return 0;
		printf("%d. ", cnt++);
		if (data.front() != '1' || data.back() != '2')
		{
			printf("NOT\n"); continue;
		}
		for (int i = 1; i < data.size() - 1; i++)
		{
			int here = data[i] - '0', before = data[i - 1] - '0', after = data[i + 1] - '0';
			if (here == 1 || here == 2) flag = 1;
			if (here == 3)
			{
				if (before != 4 && before != 6) flag = 1;
				if (after != 4 && after != 5) flag = 1;
			}
			if (here == 4)
			{
				if (before != 3 && before != 1) flag = 1;
				if (after != 3 && after != 2) flag = 1;
			}
			if (here == 5)
			{
				if (before != 3 && before != 1) flag = 1;
				if (after != 8) flag = 1;
			}
			if (here == 6)
			{
				if (before != 8) flag = 1;
				if (after != 3 && after != 2) flag = 1;
			}
			if (here == 7)
			{
				if (before != 8) flag = 1;
				if (after != 8) flag = 1;
			}
			if (here == 8)
			{
				if (before != 5 && before != 7) flag = 1;
				if (after != 6 && after != 7) flag = 1;
			}
			if (flag == 1) break;
		}
		if (flag) cout << "NOT\n";
		else cout << "VALID\n";
	}
}
