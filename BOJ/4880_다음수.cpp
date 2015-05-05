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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int a, b, c;
	while (cin >> a >> b >> c){
		if (a == b && b == c && a == 0) break;
		if (c == b + (b - a)) printf("AP %d\n", c + (b - a));
		else  printf("GP %d\n", c * (b / a));

	}
}