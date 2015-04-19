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
	freopen("\input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int p;
		char a;
		int result = 0;
		scanf("%d", &p);
		getchar();
		while ((a = getchar()) != '\n'){
			result += ((a - '0'));
			result %= (p - 1);
		}
		printf("%d\n", result );
	}
}