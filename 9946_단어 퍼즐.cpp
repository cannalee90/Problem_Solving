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
	string str_1;
	string str_2;
	int cnt = 1;
	while (cin >> str_1 >> str_2){
		if (str_1 == str_1 && str_1 == "END") break;
		sort(str_1.begin(), str_1.end());
		sort(str_2.begin(), str_2.end());
		if (str_1 == str_2)
			printf("Case %d: same\n", cnt);
		else
			printf("Case %d: different\n", cnt);
		cnt++;
	}
}