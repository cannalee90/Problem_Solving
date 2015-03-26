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
	int a, b;
	cin >> a >> b;
	if ((a + b) % 2 == 0){
		int x = (a + b) / 2;
		int y = a - x;
		if (y > x)
			swap(y, x);
		if (y < 0 || x < 0){
			cout << "-1" << endl;
		}
		else{
			cout << x << " " << y << endl;
		}
	}
	else
		printf("-1\n");

}
