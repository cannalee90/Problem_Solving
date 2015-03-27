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

vector<int> get_num(int num, int digit){
	int idx = 1;
	int length = 0;
	vector<int> result;
	while (idx <= num){
		length++;
		idx *= digit;
	}
	idx /= digit;
	for (int i = 0; i < length; i++){
		result.push_back(num / idx);
		num %= idx;
		idx /= digit;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b, c;
		int ans = 0;
		int idx = 1;
		cin >> a >> b >> c;
		if (b > c) swap(b, c);
		vector<int> res_1 = get_num(b, a);
		vector<int> res_2 = get_num(c, a);

		for (int i = 0; i < res_2.size(); i++){
			int first = 0;
			int second = res_2[i];
			if (i < res_1.size())
				first = res_1[i];
			ans += ((first + second) % a) * idx;
			idx *= a;
		}
		cout << ans << endl;
	}
}