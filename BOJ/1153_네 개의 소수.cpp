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
	int n;
	cin >> n;
	vector<int> result;
	vector<int> Prime;
	vector<int> P(n + 1);
	for (int i = 2; i <= n; i++){
		if (!P[i]){
			Prime.push_back(i);
			for (int j = i; j <= n; j += i){
				P[j] = true;
			}
		}
	}
	if (n % 2 == 0){
		result.push_back(2);
		result.push_back(2);

		for (int i = 0; i < Prime.size(); i++){
			if (binary_search(Prime.begin(), Prime.end(), n - 2 - 2 - Prime[i])){
				vector<int>::iterator itor = lower_bound(Prime.begin(), Prime.end(), n - 2 - 2 - Prime[i]);
				result.push_back(*itor);
				result.push_back(Prime[i]);
				break;
			}
		}
	}
	if (n % 2 == 1){
		result.push_back(2);
		result.push_back(3);
		for (int i = 0; i < Prime.size(); i++){
			if (binary_search(Prime.begin() + i, Prime.end(), n - 2 - 3 - Prime[i])){
				vector<int>::iterator itor = lower_bound(Prime.begin() + i, Prime.end(), n - 2 - 3 - Prime[i]);
				result.push_back(*itor);
				result.push_back(Prime[i]);
				break;
			}
		}
	}
	if (result.size() != 4){
		cout << "-1" << endl;
	}
	else{
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
	}
}