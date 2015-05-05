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
	string data;
	while (cin >> data){
		if (data == "0") return 0;
		vector<int> ans;
		for (int i = 1; i < data.size(); i++){
			int cur = i;
			int cnt = 0;
			for (int j = 0; j < ans.size(); j++){
				if (i % ans[j] == 0)
					cnt++;
			}
			if (data[i] == '0' && cnt % 2 == 1)
				ans.push_back(i);
			else if (data[i] == '1' && cnt % 2 == 0)
				ans.push_back(i);
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}