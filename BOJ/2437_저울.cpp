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

int n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<ll> weight(n);
	vector<ll> k;
	k.push_back(0);
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	sort(weight.begin(), weight.end());
	int ans = 1;
	for (int i = 0; i < n; i++){
		if (ans < weight[i]){
			cout << ans << endl;
			return 0;
		}
		else ans += weight[i];
	}
	cout << ans << endl;
}