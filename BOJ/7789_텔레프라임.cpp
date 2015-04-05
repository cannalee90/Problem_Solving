#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
	string str_a, str_b;
	cin >> str_a >> str_b;
	str_b += str_a;
	int num_new = stoi(str_b);
	int num_old = stoi(str_a);
	int limit_new = sqrt(num_new);
	int limit_old = sqrt(num_old);
	for (int i = 2; i <= limit_new; i++){
		if (num_new % i == 0){
			cout << "No" << endl;
			return 0;
		}
		if (num_old % i == 0 && limit_old >= i){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
}