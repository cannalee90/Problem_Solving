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
	ll ans = 0;
	cin >> n;
	for (int k = 0; k < n; k++){
		string s;
		cin >> s;
		vector<bool> alpha(30, false);
		alpha[s[0] - 'a'] = true;
		bool isGroupword = true;
		for (int i = 1; i < s.size(); i++){
			char cur = s[i];
			if (cur != s[i - 1] && alpha[cur - 'a']){
				isGroupword = false;
				break;
			}
			alpha[cur - 'a'] = true;
		}
		if (isGroupword)
			ans++;
	}
	cout << ans << endl;
}