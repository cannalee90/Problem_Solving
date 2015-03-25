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
	string s;
	int k;
	int mmax = -1;
	cin >> s >> k;
	for (int i = 0; i < k; i++)
		s += '*';
	int l = (s.size() + k) / 2;
	for (int i = 1; i < l; i++){  // N
		for (int j = 0; j < s.size(); j++) {	//시작점
			bool flag = true;
			for (int k = j; k < j + i; k++){ // 검사
				if (s[k] != s[k + i] && s[k + i] != '*'){
					flag = false;
					break;
				}
			}
			if (flag == true){
				mmax = max(mmax, i);
				break;
			}
		}
	}
	cout << mmax * 2 << endl;
}
