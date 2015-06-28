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
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		if (m % i == 0){
			int w = i;
			int h = m / i;
			if (w * 2 + h * 2 + 4 == n){
				cout << max(w, h) + 2 << " " << min(w, h)  + 2<< endl;
				return 0;
			}
		}
	}
}