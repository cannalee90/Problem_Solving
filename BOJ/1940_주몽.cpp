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
	int ans = 0;
	cin >> n >> m;
	vector<int> vi(n);
	for (int i = 0; i < n; i++) cin >> vi[i];
	sort(vi.begin(), vi.end());
	for (int i = 0; i < n; i++){
		if (binary_search(vi.begin() + i + 1, vi.end(), m - vi[i])){
			ans++;
		}
	}
	cout << ans << endl;
}