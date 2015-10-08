#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

using namespace std;
typedef long long ll;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> vi(n);
	for (int i = 0; i < n; i++){
		cin >> vi[i];
	}
	for (int i = 0; i < n; i++){
		int ans = 1; 
		for (int j = 0; j < n; j++){
			if (vi[i] < vi[j]) ans++;
		}
		printf("%d ", ans);
	}
	puts("");
}