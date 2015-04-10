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
	int idx = 1;
	double a, b, c;
	while (cin >> a >> b >> c){
		if (a == 0) break;
		if (a * 2 >= sqrt((b * b) + (c * c)))
			printf("Pizza %d fits on the table.\n", idx++);
		else
			printf("Pizza %d does not fit on the table.\n", idx++);
	}
}