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

int get_num(int num, int digit){
	int idx = 1;
	int result = 0;
	while (idx <= num)
		idx *= digit;
	idx /= digit;
	while (num){
		result += num / idx;
		num %= idx;
		idx /= digit;
	}
	return result;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 1000; i < 10000; i++){
		int a = get_num(i, 10);
		int b = get_num(i, 12);
		int c = get_num(i, 16);
		if (a == b && a == c && b == c)
			cout << i << endl;
	}
}