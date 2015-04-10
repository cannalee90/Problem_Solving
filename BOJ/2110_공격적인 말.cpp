#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

int n, m;

bool isPossible(vector<int> &data, const int differ){
	int point = data[0];
	vector<int>::iterator itor;
	itor = data.begin();
	int num_horse = m;
	while (num_horse--){
		itor = lower_bound(itor, data.end(), point + differ);
		if (itor == data.end())
			break;
		else
			point = *itor;
	}
	if (num_horse <= 0)
		return true;
	else
		return false;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int ans = 0;
	vector<int> data;
	scanf("%d %d", &n, &m);
	data.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	sort(data.begin(), data.end());
	int left = 0;
	int right = 1000000000;
	while (left <= right){
		int differ = (left + right) / 2;
		if (isPossible(data, differ)){
			left = differ + 1;
			ans = max(ans, differ);
		}
		else{
			right = differ - 1;
		}
	}
	cout << ans << endl;
}