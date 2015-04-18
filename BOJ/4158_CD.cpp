#include <iostream>
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

#define hash_value 5000009

int check[hash_value];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	int cnt = 0;
	while (~scanf("%d %d", &n, &m)){
		if (n == 0 && m == 0) break;
		cnt = 0;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++){
			int t1;
			scanf("%d", &t1);
			check[t1 % hash_value] = true;
		}
		for (int i = 0; i < m; i++){
			int t1;
			scanf("%d", &t1);
			if (check[t1 % hash_value])
				cnt++;
		}
		cout << cnt << endl;
	}
}