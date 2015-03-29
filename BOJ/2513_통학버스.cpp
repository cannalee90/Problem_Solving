#include <iostream>
#include <limits.h>
#include <utility>
#include <functional>
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
	int n, limit, p;
	cin >> n >> limit >> p;
	priority_queue <pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq_1;
	priority_queue <pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq_2;

	for (int i = 0; i < n; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t1 < p)
			pq_1.push(make_pair(p - t1, t2));
		else
			pq_2.push(make_pair(t1 - p, t2));
	}
	ll ans = 0, cost = 0;
	bool flag = false;
	int farthest = 0;
	while (!pq_1.empty()){
		int here_dis = pq_1.top().first;
		int here_stu = pq_1.top().second;
		pq_1.pop();

		if (!flag){
			farthest = here_dis;
			flag = true;
		}

		if (cost + here_stu <= limit){
			cost += here_stu;
		}
		else if (cost + here_stu > limit){
			cost += (limit - cost);
			here_stu -= (limit - cost);
			pq_1.push(make_pair(here_dis, here_stu));
		}

		if (cost == limit){
			cost = 0;
			ans += farthest * 2;
			flag = false;
		}
	}
	ans += farthest * 2;
	cost = 0;
	flag = false;
	farthest = 0;
	while (!pq_2.empty()){
		int here_dis = pq_2.top().first;
		int here_stu = pq_2.top().second;
		pq_2.pop();
		if (!flag){
			farthest = here_dis;
			flag = true;
		}
		if (cost + here_stu <= limit){
			cost += here_stu;
		}
		else if (cost + here_stu > limit){
			cost += (limit - cost);
			here_stu -= (limit - cost);
			pq_2.push(make_pair(here_dis, here_stu));
		}
		if (cost == limit){
			cost = 0;
			ans += farthest * 2;
			flag = false;
		}
	}
	ans += farthest * 2;

	cout << ans << endl;
}