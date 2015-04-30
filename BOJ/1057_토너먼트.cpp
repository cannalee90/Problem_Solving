#include <iostream>
#include <utility>
#include <limits.h>
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
	int n, n1, n2;
	int cnt = 0;
	cin >> n >> n1 >> n2;
	if (n1 > n2) swap(n1, n2);
	while (n1 < n2){
		n1 = (n1 / 2) + (n1 % 2);
		n2 = (n2 / 2) + (n2 % 2);
		cnt++;
	}
	cout << cnt << endl;
}