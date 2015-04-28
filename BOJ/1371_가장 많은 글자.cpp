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
	string str;
	vector<int> cnt(30, 0);
	while (cin >> str){
		for (int i = 0; i < str.size(); i++)
			cnt[str[i] - 'a']++;
	}
	int mmax = *max_element(cnt.begin(), cnt.end());
	for (int i = 0; i < 26; i++){
		if (mmax == cnt[i])
			printf("%c", i + 'a');
	}
	printf("\n");
}