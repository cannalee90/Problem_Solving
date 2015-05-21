#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int n, m, t;

inline bool cmp(const string &a, const string &b){
	int lens = min(a.size(), b.size());
	if (a.size() != b.size())
		return a.size() < b.size();
	for (int i = 0; i < lens; i++){
		if (b[i] > a[i])
			return a < b;
	}
	
	return a < b;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	vector<string> ans;
	cin >> t;
	while (t--){
		string str, temp;
		cin >> str;
		for (int i = 0; i < str.size(); i++){
			if (str[i] >= '0' && str[i] <= '9')
				temp += str[i];
			else if (temp != ""){
				if (temp.size() != 1){
					string a;
					bool isLeading = true;
					for (int i = 0; i < temp.size(); i++){
						if (isLeading  && temp[i] == '0') continue;
						else{
							isLeading = false;
							a.push_back(temp[i]);
						}
					}
					if (a.size() == 0)
						ans.push_back("0");
					else
						ans.push_back(a);
					temp = "";
				}
				else{
					ans.push_back(temp);
					temp = "";
				}
			}
		}
		if (temp != ""){
			if (temp.size() != 1){
				string a;
				bool isLeading = true;
				for (int i = 0; i < temp.size(); i++){
					if (isLeading  && temp[i] == '0') continue;
					else{
						isLeading = false;
						a.push_back(temp[i]);
					}
				}
				if (a.size() == 0)
					ans.push_back("0");
				else
					ans.push_back(a);
			}
			else{
				ans.push_back(temp);
				temp = "";
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}
