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
	cin >> n >> m;

	set<ll>result;
	vector<ll> prime(n);
	for (int i = 0; i < n; i++){
		ll t;
		cin >> t;
		result.insert(t);
		prime[i] = t;
	}
	for (int i = 0; i < n; i++){
		set<ll>::iterator itor = result.begin();
		while (true){
			ll a = *itor * prime[i];
			if (a > INT_MAX) break;
			if (result.size() > m){
				result.erase(--result.end());
				if (a>(*(--result.end()))) break;
			}
			result.insert(a);
			itor++;
		}
	}
	cout << *(--result.end()) << endl;
}