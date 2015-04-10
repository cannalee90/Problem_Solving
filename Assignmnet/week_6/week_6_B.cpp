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

int graph[8][2] = { { 7, 1 }, { 2, 8 }, { 3, 8 }, { 3, 4 }, { 7, 5 }, { 6, 5 }, { 3, 0 }, { 8, 0 } };

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		int here = 0;
		int idx = 0;
		bool isFail = false;
		string str;
		cin >> str;
		while(idx != str.size()){
			int there = str[idx++] - '0';
			here = graph[here][there];
			if (here == 8){
				isFail = true;
				break;
			}
		}
		if (isFail)
			cout << "NO" << endl;
		else if (here == 0 || here == 4 || here == 5 || here == 6)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}