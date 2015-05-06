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
#include <functional>

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	ll n;
	ll cnt = 0;
	cin >> n;
	ll num = 1;
	if (n == 0){
		cout << "0" << endl;
		return 0;
	}
	else if (n > 1022)
	{
		cout << "-1" << endl;
		return 0;
	}
	while (1){
		ll temp = num;
		ll temp2 = -1;
		ll a = 1;
		bool isDec = true;
		while (temp){
			if (temp % 10 <= temp2){
				isDec = false;
				break;
			}
			a *= 10;
			temp2 = temp % 10;
			temp /= 10;
		}
		if (isDec)
			n--;
		else{
			num += a;
			num = (num / a) * a;
			continue;
		}
		if (n == 0) {
			cout << num << endl;
			break;
		}
		num++;
	}
}
