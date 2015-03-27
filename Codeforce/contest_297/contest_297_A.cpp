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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	string s;
	int ans = 0;
	vector<int> al(30, 0);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		char cur = s[i];
		if (s[i] >= 'A' && s[i] <= 'Z'){
			if (al[s[i] - 'A'] == 0)
				ans++;
			else
				al[s[i] - 'A']--;
		}
		else if (s[i] >= 'a' && s[i] <= 'z'){
			al[s[i] - 'a'] ++;
		}
	}
	cout << ans << endl;
}