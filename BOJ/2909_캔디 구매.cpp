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
	freopen("slatkisi.in.5", "r", stdin);
#endif
	ll n, m;
	ll bill;
	cin >> n >> m;
	bill = pow(10, m);
	cout << (n + (bill / 2)) / bill * bill << endl;
}