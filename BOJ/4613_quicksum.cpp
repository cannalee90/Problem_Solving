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
	freopen("\input.txt", "r", stdin);
#endif
	string data;
	while (getline(cin, data)){
		ll ans = 0;
		if (data == "#") break;
		for (int i = 0; i < data.size(); i++){
			char cur = toupper(data[i]);
			if (cur == ' ') continue;
			else{
				ans += (cur - 'A' + 1) * (i + 1);
			}
		}
		cout << ans << endl;
	}
}