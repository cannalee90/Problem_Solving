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

typedef long long ll;
using namespace std;

int n, m, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int k, a, b, v;
	int ans = 0;
	cin >> k >> a >> b >> v;
	while (a >= 1){
		int section = 1;
		ans++;
		if (b > 0){
			if (k >= b + 1){
				section = b + 1;
				b = 0;
			}
			else{
				b -= (k - 1);
				section = k;
			}
		}
		a -= section * v;
	}
	cout << ans << endl;
}