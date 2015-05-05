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

vector<pair<int, int > > dot;
int h, w;
int k;
int n;

bool isPossible(int mid){
	int cnt = 0;
	int square = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++){
		if (visited[i]) continue;
		visited[i] = true;
		square++;
		int here_x = dot[i].first;
		cnt++;
		for (int j = 0; j < n; j++){
			int there_x = dot[j].first, there_y = dot[j].second;
			if (visited[j]) continue;
			if (here_x + mid > there_x && there_y <= mid){
				visited[j] = true;
				cnt++;				
			}
			else if (there_y > mid) return false;
		}
	}
	if (square > k || cnt != n) return false;
	else return true;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> h >> w >> k;
	cin >> n;
	dot = vector<pair<int, int> >(n);
	for (int i = 0; i < n; i++)
		cin >> dot[i].second >> dot[i].first;
	sort(dot.begin(), dot.end());
	int left = 1;
	int ans = INT_MAX;
	int right = max(h, w);
	while (left <= right){
		int mid = (left + right) / 2;
		if (isPossible(mid)){
			right = mid - 1;
			ans = min(mid, ans);
		}
		else
			left = mid + 1;
	}
	cout << ans << endl;
}