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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int k, n;
		scanf("%d %d", &k, &n);
		vector<int> vi(n), vii(n), viii, viiii;
		int left, right;
		for (int i = 0; i < n; i++) scanf("%d", &vi[i]);
		for (int i = 0; i < n; i++){
			int num = 0;
			scanf("%d", &num);
			for (int j = 0; j < n; j++){
				viii.push_back(num + vi[j]);
			}
		}
		for (int i = 0; i < n; i++) scanf("%d", &vii[i]);
		for (int i = 0; i < n; i++){
			int num = 0;
			scanf("%d", &num);
			for (int j = 0; j < n; j++) {
				viiii.push_back(num + vii[j]);
			}
		}
		sort(viii.begin(), viii.end());
		sort(viiii.begin(), viiii.end());
		vector<int>::iterator itor;
		int differ = INT_MAX;
		int ans = INT_MAX;
		for (int i = 0; i < viii.size(); i++){
			itor = lower_bound(viiii.begin(), viiii.end(), k - viii[i]);
			if (itor == viiii.end()) itor--;
			int a = *itor;
			if (itor != viiii.begin()) itor--;
			int b = *itor;
			if (abs(k - (a + viii[i])) < differ){
				differ = abs(k - (a + viii[i]));
				ans = a + viii[i];
			}
			else if (abs(k - (a + viii[i])) == differ){
				ans = min(ans, a + viii[i]);
			}
			if (abs(k - (b + viii[i])) < differ){
				differ = abs(k - (b + viii[i]));
				ans = b + viii[i];
			}
			else if (abs(k - (b + viii[i])) == differ){
				ans = min(ans, b + viii[i]);
			}
		}
		cout << ans << endl;
	}
}