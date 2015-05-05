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
	int n, multiple;
	cin >> n;
	while (cin >> multiple){
		if (multiple == 0) break;
		if (multiple % n == 0)
			printf("%d is a multiple of %d.\n", multiple, n);
		else
			printf("%d is NOT a multiple of %d.\n", multiple, n);

	}
}