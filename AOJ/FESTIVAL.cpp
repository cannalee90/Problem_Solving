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
#include <climits>
#include <functional>

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		double ans = 1000000;
		scanf("%d %d", &n, &m);
		vector<int> vi(n + 1);
		scanf("%d", &vi[1]);
		for (int i = 2; i <=n; i++){
			scanf("%d", &vi[i]);
			vi[i] += vi[i - 1];
		}
		for (int i = m; i <=n; i++){
			for (int j = i; j <=n; j++){
				double temp = (double)(vi[j] - vi[j - i]);
				ans = min(ans, temp / i);
			}
		}
		printf("%.9lf\n", ans);
	}
}