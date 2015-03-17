#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

set<int> prime;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	vector<bool> P(10010, true);
	vector<int> Prime;
	int n;
	int t;
	for (int i = 2; i <= 10000; i++){
		if (P[i]){
			Prime.push_back(i);
			for (int j = i; j <= 10000; j += i){
				P[j] = false;
			}
		}
	}
	
	for (int i = 0; i < Prime.size(); i++){
		if (Prime[i] >= 1000 && Prime[i] <= 10000)
			prime.insert(Prime[i]);
	}
	
	cin >> t;
	while (t--){
		int begin, end;
		cin >> begin;
		cin >> end;
		queue<int> que;
		vector<int> counting(10010, INT_MAX);
		que.push(begin);
		counting[begin] = 0;
		while (!que.empty()){
			int here = que.front();
			if (here == end)
				break;
			que.pop();
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 10; j++){
					string temp = to_string(here);
					temp[i] = j + '0';
					int number = stoi(temp);
					if (prime.count(number) && counting[number] > counting[here] + 1){
						que.push(number);
						counting[number] = counting[here] + 1;
					}
				}
			}
		}
		cout << counting[end] << endl;
	}
}
