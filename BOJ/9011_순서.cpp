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
int ai[110];
int ans[110];
int sorted[110];


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &test);
	while (test--){
		bool isPossible = true;
		scanf("%d", &n);
		memset(ai, 0, sizeof(ai));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++) scanf("%d", &ai[i]);
		if (n == 1 && ai[0] != 0) isPossible = false;
		ans[0] = 1;
		for (int i = 1; i < n; i++){
			if (ai[i] > i){
				isPossible = false;
				break;
			}
			ans[i] = ai[i] + 1;
			for (int j = i - 1; j >= 0; j--)
				if (ans[j] >= ans[i]) ans[j]++;
		}
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (ans[i] == ans[j]) isPossible = false;
			}
		}
		if (*max_element(ans, ans + n) != n && *min_element(ans, ans + n) != 1) isPossible = false;
		if (isPossible){
			for (int i = 0; i < n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
}