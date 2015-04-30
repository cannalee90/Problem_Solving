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
	int t;
	cin >> t;
	while (t--){
		char a;
		string str;
		vector<string> data;
		set<string> visited;
		getchar();
		while ((a = getchar()) != '\n'){
			if(a >= 'a' && a <= 'z')
				str += a;
			else{
				data.push_back(str);
				str.clear();
			}
		}
		data.push_back(str);
		string str1, str2, str3;
		vector<string> ans;
		while (cin >> str1 >> str2 >> str3){
			if (str1 == "what" && str2 == "does" && str3 == "the"){
				cin >> str2 >> str3;
				break;
			}
			else
				visited.insert(str3);
		}
		for (int i = 0; i < data.size(); i++){
			if (!visited.count(data[i]))
				cout << data[i] << " ";
		}
		cout << endl;
	}
}