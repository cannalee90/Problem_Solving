#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;



int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	set<pair<int, int > > query;
	for (int i = 0; i < m; i++){
		int t1, t2;
		cin >> t1 >> t2;
		if (t1 == t2) continue;
		if (t1 > t2) 
			swap(t1, t2);
		query.insert(make_pair(t1, t2));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			for (int k = j + 1; k <= n; k++){
				if (query.count(make_pair(i, j)) || query.count(make_pair(j, k)) || query.count(make_pair(i, k)))
					continue;
				else
					ans++;
			}
		}
	}
	cout << ans << endl;
}

