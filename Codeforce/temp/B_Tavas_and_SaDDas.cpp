#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	cin >> n;
	ll num = 0;
	vector<ll> ans;
	ll idx = 0;
	if (n < 4){
		cout << "0" << endl;
		return 0;
	}
	ans.push_back(4);
	ans.push_back(7);
	if (n < 7){
		cout << "1" << endl;
		return 0;
	}

	while (1){
		bool isDone = false;
		if (ans.size() == 0){
		}
		else{
			int a = ans.size();
			for (ll i = idx; i < ans.size(); i++){
				ll temp = ans[i] * 10 + 4LL;
				if (temp > n){
					isDone = true;
					break;
				}
				ans.push_back(temp);
				temp = ans[i] * 10 + 7LL;
				if (temp > n){
					isDone = true;
					break;
				}
				ans.push_back(temp);
			}
			idx = a;
		}
		if (isDone) break;
	}
	cout << ans.size() << endl;
}