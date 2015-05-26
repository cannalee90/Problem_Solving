#include <iostream>
#include <utility>
#include <functional>
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

typedef long long ll;
using namespace std;

int n, m, t;
const int M = 100001;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	t = 1;
	while (t--){
		scanf("%d", &n);
		int data[M], t = -1, ans = INT_MIN;
		int st[M], width[M];
		for (int i = 1; i <= n; i++) 	scanf("%d", &data[i]);
		data[n + 1] = 0;
		for (int i = 1; i <= n + 1; i++){
			int height = data[i], w = i;
			if (t == -1 || st[t] < height){
				st[++t] = height;
				width[t] = w;
			}
			else{
				while (st[t] >= height){
					ans = max(ans, st[t] * (i - width[t]));
					w = width[t--];
					if (t == -1) 	break;
				}
				st[++t] = height;
				width[t] = w;
			}
		}
		cout << ans << endl;
	}
}
