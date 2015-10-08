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

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 1; i < n; i++){
		for (int j = i; j >= 1; j--){
			if (v[j] <= v[j - 1]){
				while (v[j] <= v[j - 1]){
					v[j]++;
					ans++;
				}
			}
			else
				break;
		}
	}
	cout << ans << endl;
}