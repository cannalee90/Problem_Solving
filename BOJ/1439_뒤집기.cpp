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
	cin >> data;
	int ans[2] = { 0 };
	if (data[0] == '0')  ans[0]++;
	else ans[1]++;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i - 1] != data[i])
		{
			ans[data[i] - '0'] ++;
		}
	}
	cout << min(ans[0], ans[1]) << endl;
}
