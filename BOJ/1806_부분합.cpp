#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>
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
	vector<int> data;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	int min_length = INT_MAX;
	int sum = 0;
	int begin = 0;
	for (int i = 0; i < n; i++){
		sum += data[i];
		if (sum >= m){
			while (sum - data[begin] >= m){
				sum -= data[begin++];
			}
			if (min_length > i - begin + 1){
				min_length = i - begin + 1;
			}
		}
	}
	if (min_length == INT_MAX)
		cout << "0" << endl;
	else
		cout << min_length << endl;
}