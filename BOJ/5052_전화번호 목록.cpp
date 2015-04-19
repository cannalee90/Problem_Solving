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
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<string> data;
		for (int i = 0; i < n; i++){
			string str;
			cin >> str;
			data.push_back(str);
		}
		sort(data.begin(), data.end());
		bool isCons = true;
		for (int i = 0; i < n - 1; i++){
			if (data[i].size() < data[i + 1].size()){
				bool isSame = true;
				for (int j = 0; j < data[i].size(); j++){
					if (data[i][j] != data[i + 1][j]){
						isSame = false;
						break;
					}
				}
				if (isSame){
					isCons = false;
					break;
				}
			}
		}
		if (isCons)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}