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

using namespace std;
typedef long long ll;

int coin[50];
int n;
int ans = INT_MAX;

void sol(int pos){
	if (pos == n){
		int tail = 0;
		for (int i = 1; i < (1 << n); i *= 2){
			int cnt = 0;
			for (int j = 0; j < n; j++){
				if (!(coin[j] & i))
					cnt++;
			}
			if (cnt < n - cnt) tail += cnt;
			else tail += n - cnt;
		}
		ans = min(ans, tail);
		return;
	}
	coin[pos] = ~coin[pos];
	sol(pos + 1);
	coin[pos] = ~coin[pos];
	sol(pos + 1);
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	char ch;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = (1 << n - 1); j > 0; ){
			cin >> ch;
			if (ch == 'H') coin[i] |= j;
			j /= 2;
		}
	}
	sol(0);
	cout << ans << endl;
}