#include <iostream>
#include <cstdlib>
#include <ctime>
#include <numeric>
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
	int n = 5;
	int a, ans =0 ;
	for (int i = 0; i < n; i++){
		cin >> a;
		ans += a;
	}
	cout << ans << endl;
}