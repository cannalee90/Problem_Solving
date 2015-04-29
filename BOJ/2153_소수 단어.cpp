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
	string str;
	ll  total = 0;
	cin >> str;
	for(int i = 0; i<str.size(); i++)
		total += tolower(str[i]) - 'a' + 1;
	for (int i = 2; i < total; i++){
		if (total % i == 0) {
			cout << "It is not a prime word." << endl;
			return 0;
		}
	}
	cout << "It is a prime word." << endl;
}