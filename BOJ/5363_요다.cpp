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
int t;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	getchar();
	while (t--){
		string str;
		int idx = 0;
		getline(cin, str);
		int flag = 0;
		for (int i = 0; i < str.size(); i++){
			if (flag >= 2){
				cout << str[i];
				if (idx == 0)
					idx = i;
			}
			if (str[i] == ' ')
				flag++;
		}
		cout << " ";
		for (int i = 0; i < idx; i++)
			cout << str[i];
		cout << endl;
	}
}