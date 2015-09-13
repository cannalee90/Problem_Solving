#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
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
	ll ans = 0;
	scanf("%lld", &n);
	vector<ll> vi(n);
	stack<pair<ll, ll > > sp;
	pair<ll, ll > temp;
	for (ll i = 0; i < n; i++) scanf("%lld", &vi[i]);
	for (ll i = 0; i < n; i++){
		if (sp.empty()){
			sp.push(make_pair(vi[i], 0));
		}
		else{
			ll conse = 0;
			ll p = 0;
			while (!sp.empty() && sp.top().first < vi[i]){
				temp = sp.top();
				sp.pop();
				temp.second += 1LL;
				ans += temp.second;

				if (sp.empty()){
					break;
				}
				else{
					sp.top().second += 1LL + conse;
				}
				if (sp.top().first == temp.first){
					conse++;
				}
				else
					conse = 0;
			}
			sp.push(make_pair(vi[i], 0));
		}
	}
	ll conse = 0;
	ll last = 0;
	while (sp.size() > 1){
		temp = sp.top();
		sp.pop();
		ans += temp.second + conse;

		if (sp.empty()){
			break;
		}
		else
			sp.top().second += 1LL;
		if (sp.top().first == temp.first){
			conse++;
		}
		else
			conse = 0;
		last = temp.first;
	}
	for (; !sp.empty(); sp.pop()){
		
		ans += sp.top().second + 1;
	}
	cout << ans  - 1<< endl;
}