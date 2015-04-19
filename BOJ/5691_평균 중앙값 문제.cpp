#include <iostream>
#include <utility>
#include <limits.h>
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
int t;


int main(){
#ifdef _CONSOLE
	freopen("\input.txt", "r", stdin);
#endif
	ll a, b;
	while (cin >> a >> b){
		if (a == b && a == 0) break;
		cout << a - abs(b - a) << endl;
	}
}