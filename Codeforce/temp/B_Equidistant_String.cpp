#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

const int M = 100010;
int n, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string st, en;
	int differ = 0;
	cin >> st >> en;
	for (int i = 0; i < st.size(); i++){
		if (st[i] != en[i]) {
			differ++;
		}
	}
	if (differ % 2 == 0){
		differ /= 2;
		for (int i = 0; i < st.size(); i++){
			if (st[i] != en[i] && differ != 0){
				st[i] = en[i];
				differ--;
			}
		}
		cout << st;
	}
	else
		cout << "impossible";
	puts("");
}