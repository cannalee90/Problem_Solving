#include <iostream>
#include <limits.h>
#include <climits>
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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> data(n);
	set<int> check;
	for (int i = 0; i < n; i++){
		cin >> data[i];
		check.insert(data[i]);
	}
	sort(data.begin(), data.end());
	int mmax = -1;
	for (int i = n - 1; i >= 0; i--){
		int target = data[i];
		for (int j = 0; j < i; j++){
			for (int k = j; k < i; k++){
				if (check.count(target - (data[j] + data[k])))
				{
					cout << target << endl;
					return 0;
				}
				else if (data[j] + data[k] > target)
					break;
			}
		}
	}

}