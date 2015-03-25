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
	long long ans = 0;
	cin >> n;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= i; j++){
			ans += i + j;
		}
	}
	cout << ans << endl;
}