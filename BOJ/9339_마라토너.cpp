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

int t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> t;
	while (t--){
		int n, m, q;
		int mmin;
		int ans = 0;
		int ans1 = 0;
		int mminute = INT_MAX;
		cin >> n;
		vector<int> data(n);
		set<int> check;
		for (int i = 0; i < n; i++){
			cin >> q;
			check.insert(q);
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			int num, hour, minute;
			cin >> num >> hour >> minute;
			if (hour == -1 && minute == -1)
				continue;
			if (check.count(num)){
				if (hour < 6){
					ans++;
					if (minute  + (hour * 60)  < mminute){
						mminute = minute  + (hour * 60);
						ans1 = num;
					}
				}
				else if (hour == 6 && minute == 0){
					ans++;
					if (minute + (hour * 60)  < mminute){
						mminute = minute + (hour * 60);
						ans1 = num;
					}
				}
			}
		}
		cout << ans1 << " " << ans << endl;
	}
}