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

int n, m, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	set<string> ans;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++){
		for (int k = 0; k < 26; k++)
		{
			string temp;
			int tidx = 0, sidx = 0;
			for (int j = 0; j <=str.size(); j++){
				if (i == j) temp.push_back(k + 'a');
				else{
					temp.push_back(str[sidx++]);
				}
			}
			ans.insert(temp);
		}
	}
	for (int i = 0; i < 26; i++){
		string temp = str;
		temp.push_back(i + 'a');
		ans.insert(temp);
	}
	cout << ans.size() << endl;
}