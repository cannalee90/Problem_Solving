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

int n, m, t;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	pair<int, int > p;
	priority_queue<pair<int, int > > pq;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p.second;
		cin >> p.first;
		pq.push(p);
	}
	int time = pq.top().first;
	while (!pq.empty()){
		if (pq.top().first <= time){
			time = pq.top().first;
			time -= pq.top().second;
		}
		else{
			time -= pq.top().second;
		}
		pq.pop();
	}
	if (time < 0) cout << "-1" << endl;
	else cout << time  << endl;
}

