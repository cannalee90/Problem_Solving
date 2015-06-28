#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
#include <utility>
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
	int idx = 0;
	string str, cy;
	getline(cin, str);
	cin >> cy;
	char alpha[30];
	for (int i = 1; i <= 26; i++)
		alpha[i] = 'a' + i - 1;
	for (int i = 0; i < str.size(); i++){
		char cur = str[i];
		if (cur == ' ')	{
			cout << cur;
		}
		else{
			cur = (cur - 'a') - (cy[idx] - 'a');
			if (cur <= 0) cur += 26;
			printf("%c", alpha[cur]);
		}
		idx++;
		idx %= cy.size();
	}
}