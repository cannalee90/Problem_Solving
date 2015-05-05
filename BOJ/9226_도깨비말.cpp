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
	while (cin >> str){
		if (str == "#") return 0;
		int idx = 0;
		int len = str.size();
		for (int i = 0; i < len; i++){
			if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
				str.push_back(str[i]);
				if (i == len - 1)
					idx = i + 1;
			}
			else{
				idx = i;
				break;
			}
		}
		str += "ay";
		for (int i = idx; i < str.size(); i++)
			cout << str[i];
		cout << endl;
	}
}