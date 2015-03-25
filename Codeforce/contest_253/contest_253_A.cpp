#include <iostream>
#include <limits.h>
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

bool alphabet[30];


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'z')
			alphabet[s[i] - 'a'] = true;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++){
		if (alphabet[i] == true)
			ans++;
	}
	cout << ans << endl;
}
