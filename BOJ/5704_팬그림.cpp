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
#include <climits>
#include <float.h>
#include <stack>

typedef long long ll;

using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	while (true)
	{
		string a;
		vector<bool> check(30, false);
		int alphabet = 26;
		getline(cin, a);
		if (a[0] == '*') return 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == ' ') continue;
			if (check[a[i] - 'a'] == false)
			{
				check[a[i] - 'a'] = true;
				alphabet--;
			}
		}
		if (alphabet == 0) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}
