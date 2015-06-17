#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	string n;
	while (cin >> n){
		if (n == "0") break;
		while (n.size() >= 2){
			ll ans = 1;
			cout << n << " ";
			for (int i = 0; i < n.size(); i++)
				ans *= n[i] - '0';
			n = to_string(ans);
		}
		cout << n << endl;
	}
}