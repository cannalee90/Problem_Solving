#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

int n, m, test;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n >> m){
		int ans = 0;
		for (int i = n; i <= m; i++){
			vector<int> cnt(10, 0);
			int num = i;
			bool isSame = true;
			while (num){
				cnt[num % 10]++;
				num /= 10;
			}
			for (int i = 0; i < 10; i++){
				if (cnt [i]> 1){
					isSame = false;
					break;
				}
			}
			if (isSame) ans++;
		}
		cout << ans << endl;
	}
	
}