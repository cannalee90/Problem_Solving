#include <iostream>
#include <limits.h>
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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> num;
	vector<int> DP(n + 1, INT_MAX);
	for (int i = 1; i * i <= n; i++){
		num.push_back(i * i);
	}
	DP[0] = 0;
	for (int i = 0; i < num.size(); i++){
		int current_num = num[i];
		for (int j = current_num; j <= n; j++){
			if (DP[j - current_num] + 1 < DP[j]){
				DP[j] = DP[j - current_num] + 1;
			}
		}
	}
	cout << DP[n] << endl;
}