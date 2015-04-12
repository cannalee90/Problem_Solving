#include <iostream>
#include <functional>
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

int n, m;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<int> data;
	while (n || m){
		data.push_back(n % 10 + m % 10);
		n /= 10;
		m /= 10;
	}
	for (int i = data.size() - 1; i >= 0; i--)
		cout << data[i];
	cout << endl;
}