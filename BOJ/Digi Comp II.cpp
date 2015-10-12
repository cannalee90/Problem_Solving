#include <iostream>
#include <utility>
#include <functional>
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

#define INF 987654321

int main(){
	freopen("input.txt", "r", stdin);
	ll n, m;
	cin >> n >> m;

	vector<vector<ll> > graph(m + 1);
	vector<ll> indegree(m + 1);
	vector<ll> status(m + 1);
	vector<ll> ball(m + 1);
	queue<ll> que;

	for (ll i = 0; i < m; i++) {
		char c;
		ll l, r;
		cin >> c >> l >> r;
		graph[i + 1].push_back(l);
		graph[i + 1].push_back(r);
		indegree[l]++;
		indegree[r]++;
		(c == 'R') ? status[i + 1] = 1 : status[i + 1] = 0; //left == 0 right == 1

	}
	
	for (ll i = 0; i <= m; i++) {
		if (indegree[i] == 0)
			que.push(i);
	}

	ball[1] = n;

	while (!que.empty()) {

		ll here = que.front();
		que.pop();
		if (here == 0) 
			continue;
		ll here_ball = ball[here];
		ll left = graph[here][0];
		ll right = graph[here][1];

		ball[here] = 0;


		if (here_ball % 2) {
			(status[here] == 0) ? ball[left] ++ : ball[right]++;
			(status[here] == 0) ? status[here] = 1 : status[here] = 0;
		}

		ball[left] += here_ball / 2LL;
		ball[right] += here_ball / 2LL;
		indegree[left]--;
		indegree[right]--;

		if (indegree[left] == 0)
			que.push(left);
		if (indegree[right] == 0 && left != right)
			que.push(right);

	}

	for (int i = 1; i <= m; i++) {
		char ans = (status[i] == 0) ? 'L' : 'R';
		cout << ans;
	}
}