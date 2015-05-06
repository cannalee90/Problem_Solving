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
	int n, m;
	cin >> n >> m;
	vector<int> DP(m + 1, INT_MAX);
	priority_queue < pair<int, pair<int, int > >, vector < pair<int, pair<int, int > > > , greater<pair<int, pair<int, int > > > > pq;
	DP[0] = 0;

	for (int i = 0; i < n; i++){
		int here, there, dis;
		cin >> here >> there >> dis;
		if(there <= m)
			pq.push(make_pair(there, make_pair( dis, here)));
	}
	for (int i = 1; i <= m; i++){
		while (!pq.empty() && pq.top().first == i){
				if (DP[pq.top().second.second] + pq.top().second.first < DP[i]){
					DP[i] = DP[pq.top().second.second] + pq.top().second.first;
				}
				pq.pop();
			}
		if (DP[i] > DP[i - 1] + 1){
			DP[i] = DP[i - 1] + 1;
		}
	}
	cout << DP [m] << endl;
}