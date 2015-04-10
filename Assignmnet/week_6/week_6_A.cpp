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
	int t;
	int qutient_rest[10] = { 1, 2, 4, 3 };
	int qutient_six[10] = {4,2};
	int qutient_nine[10] = { 1, 2, 4, 8, 7, 5};
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		int modular, length;
		ll ans = 0;
		string bits;
		cin >> modular;
		cin >> length;
		cin >> bits;
		reverse(bits.begin(), bits.end());
		for (int i = 0; i < bits.size(); i++){
			if (modular % 2 == 0 && i == 3 && modular != 6) break;
			if (bits[i] == '1'){
				int idx;
				if (modular == 3 || modular == 6) idx = 2;
				else if (modular == 5) idx = 4;
				else if (modular == 7) idx = 3;
				else if (modular == 9) idx = 6;
				else idx = 3;
				if(modular == 9)
					ans += qutient_nine[i % idx];
				else if(modular == 6 && i != 0)
					ans += qutient_six[i % idx];
				else if (modular == 6 && i == 0)
					ans += 1;
				else
					ans += qutient_rest[i % idx];
				ans %= modular;
			}
		}
		cout << ans << endl;
	}
}