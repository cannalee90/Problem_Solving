#include <iostream>
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
#include <climits>
#include <stack>

typedef long long ll;

using namespace std;

int n, new_restarea, l;

bool isPossible(const int &dis, const vector<int> &coor){
	int idx = 1;
	int temp = 0;
	int here = coor[0];
	while (idx != coor.size()){
		int there = coor[idx];
		if (there - here <= dis){
			idx++;
			here = there;
		}
		else{
			temp++;
			here += dis;
		}
		if (temp > new_restarea) return false;
	}
	return true;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int ans = INT_MAX;
	cin >> n >> new_restarea >> l;
	vector<int> coor(n+1);
	coor[0] = 0;

	for (int i = 1; i <=n; i++)
		cin >> coor[i];
	sort(coor.begin(), coor.end());
	coor.push_back(l);
	int left = 1, right = 1000;
	while (left <= right){
		int dis = (left + right) / 2;
		if (isPossible(dis, coor)){
			right = dis - 1;
			ans = min(ans, dis);
		}
		else{
			left = dis + 1;
		}
	}
	cout << ans << endl;
}

