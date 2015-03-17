#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
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
	vector<bool> P(1000001, true);
	vector<int> Prime;
	cin >> n;
	for (int i = 2; i <= 1000000; i++){
		if (P[i]){
			Prime.push_back(i);
			for (int j = i; j <= n; j += i){
				P[j] = false;
			}
		}
	}
	for (int i = 0; i < n; i++){
		long long m;
		bool flag = true;
		cin >> m;
		for (int j = 0; j < Prime.size(); j++){
			if (m % Prime[j] == 0){
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if (flag){
			cout << "YES" << endl;
		}
	}
}