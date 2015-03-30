#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

bool isPossible(int num){
	if (num >= 10 && num <= 34) 
		return 1;
	return 0;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	vector<int> DP(s.size() + 1, 0);
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 1; i < s.size(); i++){
		string temp;
		temp += s[i- 1];
		temp += s[i];
		if (s[i] != '0')
			DP[i+ 1] = DP[i];
		if (isPossible(stoi(temp)))
			DP[i + 1] += DP[i - 1];
	}
	cout << DP[s.size()] << endl;
}