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
	const int limit = 1000000;
	vector<int> Prime;
	vector<bool> P(limit + 10, true);
	for (int i = 2; i <= limit; i++){
		if (P[i]){
			Prime.push_back(i);
			for (int j = i; j <= limit; j += i){
				P[j] = false;
			}
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		vector<int>::iterator itor = lower_bound(Prime.begin(), Prime.end(), t);
		printf("%d\n", itor - Prime.begin());
	}
}
