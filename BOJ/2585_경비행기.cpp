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

using namespace std;


bool isPossible(vector<vector<int> > &graph, int mid, int k){
	int  n = graph.size();
	vector<pair<int, int > > arr(n, pair<int, int>(INT_MAX, INT_MAX));
	arr[0].first = 0;
	arr[0].second = 0;
	priority_queue < pair<int, pair<int, int > > > que;
	que.push(make_pair(0, make_pair(0, 0)));
	while (!que.empty()){
		int vertex = que.top().first;
		int cnt = que.top().second.first;
		int dis = que.top().second.second;
		que.pop();
		for (int i = 0; i < n; i++){
			int cost = dis + graph[vertex][i];
			int ccnt = cnt;
			if (cost > mid){
				ccnt++;
				cost = graph[vertex][i];
			}
			if (cost <= mid && arr[i].first >= ccnt && arr[i].second > cost){
				arr[i].first = ccnt;
				arr[i].second = cost;
				que.push(make_pair(i, make_pair(ccnt, cost)));

			}
		}
	}
	return k >= arr[1].first;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int k, n;
	scanf("%d %d", &n, &k);
	vector<pair<int, int > > data(n + 2);
	data[0].first = 0;
	data[0].second = 0;
	data[1].first = 10000;
	data[1].second = 10000;
	for (int i = 2; i < n + 2; i++) scanf("%d %d", &data[i].first, &data[i].second);
	vector<vector<int> > graph(n + 2, vector<int>(n + 2));
	for (int i = 0; i <n + 2; i++){
		for (int j = i + 1; j <n + 2; j++){
			int x = abs(data[i].first - data[j].first);
			int y = abs(data[j].second - data[i].second);
			double a = sqrt(x * x + y * y);
			if (a == (int)a){
				graph[i][j] = a / 10;
				graph[j][i] = a / 10;
			}
			else{
				graph[i][j] = a / 10 + 1;
				graph[j][i] = a / 10 + 1;
			}
		}
	}
	int left = 0, right = ceil(sqrt(10000 * 10000 * 2));
	int ans = INT_MAX;
	while (left <= right){
		int mid = (left + right) / 2;
		if (isPossible(graph, mid, k)){
			right = mid - 1;
			ans = mid;
		}
		else
			left = mid + 1;
	}
	cout << ans << endl;
}