#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

using namespace std;
map<string, int> hashing;
vector<vector<int> > tree;
int n, cnt;

void input(){
	string str_1, str_2, str_3;
	int n_1, n_2, n_3;
	int n;
	cin >> n;
	cin >> str_1;
	hashing[str_1] = cnt++;
	tree = vector<vector<int> >(n + 1);
	for (int i = 0; i < n; i++){
		cin >> str_1 >> str_2 >> str_3;
		n_1 = hashing[str_1];
		n_2 = cnt++;
		hashing[str_2] = n_2;
		if (str_3 == "부모"){
		}
		if (str_3 == "형제"){
			
		}
		if (str_3 == "자녀"){

		}
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	input();
}