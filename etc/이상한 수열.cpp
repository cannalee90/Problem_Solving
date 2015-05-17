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

ll n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	scanf("%lld", &n);
	vector<ll> vi(n);
	for (ll i = 0; i < n; i++){
		scanf("%lld", &vi[i]);
	}
	scanf("%lld", &m);
	if (m <= n){
		printf("%lld\n", vi[m - 1]);
		return 0;
	}
	sort(vi.begin(), vi.end());
	vi.resize(unique(vi.begin(), vi.end()) - vi.begin());
	vector<ll>::iterator itor = lower_bound(vi.begin(), vi.end(), vi.size());

	if (itor == vi.end()){
		printf("%lld\n", (m - n) + (vi.size() - 1)); // ¹«ÇÑ
	}
	else{
		if ((*itor - vi.size() + 1) + n <= m) // ¾Æ´Ò¶§
			printf("%lld\n", *itor);
		else{
			printf("%lld\n", (m - n) + (vi.size() - 1));

		}
	}
}