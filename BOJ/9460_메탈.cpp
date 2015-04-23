#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <cstdlib>
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

vector<pair<int, int> > coor;
int n, k;


bool isPossible(double cost){
	int cnt = 1;
	int lowest = coor[0].second;
	int highest = coor[0].second;
	for (int i = 1; i < coor.size(); i++){
		if (abs(lowest - coor[i].second) <= (cost * 2.0) && abs(highest - coor[i].second) <= (cost * 2.0)){
			lowest = min(lowest, coor[i].second);
			highest = max(highest, coor[i].second);
		}
		else{
			cnt++;
			lowest = coor[i].second;
			highest = coor[i].second;
		}
		if (cnt > k)
			return false;
	}
	return true;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--){
		cin >> n >> k;
		coor.clear();
		for (int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			coor.push_back(make_pair(x, y));
		}
		sort(coor.begin(), coor.end());
		double ans = 100000000000;
		double left = 0, right = 200000000;
		double cost;
		double pre_cost = 100000000000;
		while (true){
			cost = (left + right) / 2.0;
			if (abs(pre_cost - cost) <= 0.001)
				break;
			if (isPossible(cost)){
				ans = cost;
				right = cost;
			}
			else
				left = cost;
			pre_cost = cost;
		}
		printf("%.1lf\n", ans);
	}
}