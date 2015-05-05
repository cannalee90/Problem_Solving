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

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int fuel, des;
	int dis = 0;
	int ans = 0;
	int cnt = 0;
	vector<pair<int, int > > station;
	cin >> n;
	for (int i = 0; i < n; i++){
		int d, f;
		cin >> d >> f;
		station.push_back(make_pair(d, f));
	}
	priority_queue<pair<int, int> > pq;
	sort(station.begin(), station.end());
	cin >> des >> fuel;
	int idx = 0;
	while (des > fuel){
		for (int i = idx; i < n; i++){
			if (fuel >= station[i].first){
				pq.push(make_pair(station[i].second, station[i].first));
				idx = i + 1;
			}
			else
				break;
		}
		if (pq.empty()){
			cout << "-1" << endl;
			return 0;
		}
		else{
			ans++;
			fuel += pq.top().first;
			pq.pop();
		}
	}
	cout << ans << endl;
}