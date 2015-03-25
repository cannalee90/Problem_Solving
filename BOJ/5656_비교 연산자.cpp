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

bool compare_operation(int a, int b, string cmp){
	if (cmp == "=="){
		if (a == b) return true;
		else return false;
	}
	if (cmp == ">="){
		if (a >= b) return true;
		else return false;
	}
	if (cmp == "!="){
		if (a != b) return true;
		else return false;
	}
	if (cmp == "<="){
		if (a <= b) return true;
		else return false;
	}
	if (cmp == ">"){
		if (a > b) return true;
		else return false;
	}
	if (cmp == "<"){
		if (a < b) return true;
		else return false;
	}
	return false;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n = 1;
	while (1){
		string t1, t2, t3;
		string s;
		getline(cin, s);
		int idx = 0;
		int a, b;
		for (; s[idx] != ' '; idx++){
			t1 += s[idx];
		}
		idx++;
		for (; s[idx] != ' '; idx++){
			t3 += s[idx];
		}
		idx++;
		for (; idx < s.size(); idx++){
			t2 += s[idx];
		}
		if (t3 == "E")
			break;
		a = stoi(t1);
		b = stoi(t2);
		if (compare_operation(a, b, t3)){
			printf("Case %d: true\n", n);
		}
		else{
			printf("Case %d: false\n", n);
		}
		n++;
	}
}