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

#define INF 987654321

bool isPrime(ll num) {
	ll limit = sqrt(num);
	for (ll i = 2; i <= limit; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string str;
	ll num = 0;
	ll ori = 0;
	cin >> str;

	ori = stoll(str);
	reverse(str.begin(), str.end());


	//coner case.. T_T
	if (ori == 0 || ori == 1)  {
		puts("no");
		exit(0);
	}

	for (int i = 0; i < str.size(); i++) {
		char c;
		c = str[i];
		if (c == '3' || c == '4' || c == '7') {
			puts("no");
			exit(0);
		}
		else if (c == '6' || c == '9')
			(c == '9') ? c = '6' : c = '9';
		num *= 10LL;
		num += c - '0';
	}

	if (isPrime(ori) && isPrime(num))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}