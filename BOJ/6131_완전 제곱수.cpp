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
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= 500; i++){
		for (int j = 1; j < i; j++){
			if (i * i == j * j + n){
				ans++;
			}
		}
	}
	cout << ans << endl;
}