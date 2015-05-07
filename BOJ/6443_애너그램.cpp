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
#include <functional>

typedef long long ll;
using namespace std;


int n;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	char str[100];
	scanf("%d", &t);
	while (t--){
		scanf("%s", str);
		int lens = strlen(str);
		sort(str, str + lens);
		do{
			printf("%s\n", str);
		} while (next_permutation(str, str + lens));
	}
}