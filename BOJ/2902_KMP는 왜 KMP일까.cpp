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
	string ans;
	cin >> str;
	ans += str[0];
	bool flag = false;
	for (int i = 1; i <str.size(); i++){
		if (flag == true){
			ans += str[i];
			flag = false;
		}
		if (str[i] == '-')
			flag = true;
	}
	cout << ans << endl;
}
