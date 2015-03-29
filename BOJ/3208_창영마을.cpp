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
int a[5];


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string b;
	cin >> b;
	a[1] = 1;
	for (int i = 0; i < b.size(); i++){
		char cur = b[i];
		if (cur == 'A')
			swap(a[1], a[2]);
		if (cur == 'B')
			swap(a[2], a[3]);
		if (cur == 'C')
			swap(a[1], a[3]);
	}
	for (int i = 1; i <= 3; i++)
		if (a[i])
			cout << i << endl;
}