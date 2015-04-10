#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll a, b, c;
	cin >> a >> b >> c;
	if (b >= c)
		cout << "-1" << endl;
	else
		cout << (a / (c - b)) + 1 << endl;

}