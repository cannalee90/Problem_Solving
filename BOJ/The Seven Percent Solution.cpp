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
	char a;
	while ((a = getchar()) != '#'){
		if (a == ' ') cout << "%20";
		else if (a == '!') cout << "%21";
		else if (a == '$') cout << "%24";
		else if (a == '%') cout << "%25";
		else if (a == '(') cout << "%28";
		else if (a == ')') cout << "%29";
		else if (a == '*') cout << "%2a";
		else cout << a;
	}
}