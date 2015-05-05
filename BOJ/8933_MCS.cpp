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

#define hv 200007
int hashtable[hv];
ll cnt[4];

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif

	int t;
	cin >> t;
	while (t--){
		int n;
		char str[60001];
		string temp;
		int ans = 1;
		scanf("%d %s", &n, str);
		int idx = 0;

		memset(cnt, 0, sizeof(cnt));

		memset(hashtable, 0, sizeof(hashtable));

		for (int i = 0; i < n; i++){
			temp += str[i];
			if (str[i] == 'A') idx = 0;
			else if (str[i] == 'G') idx = 1;
			else if (str[i] == 'C') idx = 2;
			else if (str[i] == 'T') idx = 3;
			cnt[idx]++;
		}
		ll value = 0;
		value += cnt[0];
		value += cnt[1] * 600;
		value += cnt[2] * 360000;
		value += cnt[3] * 216000000;

		hashtable[value % hv]++;
		int lens = strlen(str);
		for (int i = n; i < lens; i++){
			if (str[i] == 'A') idx = 0;
			else if (str[i] == 'G') idx = 1;
			else if (str[i] == 'C') idx = 2;
			else if (str[i] == 'T') idx = 3;
			cnt[idx]++;
			if (str[i - n] == 'A') idx = 0;
			else if (str[i - n] == 'G') idx = 1;
			else if (str[i - n] == 'C') idx = 2;
			else if (str[i - n] == 'T') idx = 3;
			cnt[idx]--;
			value = 0;
			value += cnt[0];
			value += cnt[1] * 600;
			value += cnt[2] * 360000;
			value += cnt[3] * 216000000;
			hashtable[value % hv]++;
			ans = max(ans, hashtable[value % hv]);
		}
		cout << ans << endl;
	}
}