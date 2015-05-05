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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif

	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	pair<int, string> pair1, pair2, one;
	while (t--){
		string  a;
		string str;
		int n;
		cin >> n;
		vector<int> lens(30, 0);
		priority_queue < pair<int, string>, vector < pair<int, string > >, greater<pair<int, string > > > pq;
		for (int i = 0; i < n; i++){
			int num;
			cin >> num >> a;
			pq.push(make_pair(num, a));
		}
		while (pq.size() != 1){
			pair1 = pq.top(), pq.pop();
			pair2 = pq.top(), pq.pop();
			one.first = pair1.first + pair2.first;
			one.second = pair1.second + pair2.second;
			for (int i = 0; i < one.second.size(); i++)
				lens[one.second[i] - 'a'] ++;
			pq.push(one);
		}
		cin >> str;
		int ans = 0;
		for (int i = 0; i < str.size(); i++)
			ans += lens[str[i] - 'a'];
		cout << ans << endl;
	}
}