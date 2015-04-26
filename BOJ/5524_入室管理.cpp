#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++){
			char a = str[j];
			printf("%c", tolower(a));
		}
		cout << endl;
	}
}