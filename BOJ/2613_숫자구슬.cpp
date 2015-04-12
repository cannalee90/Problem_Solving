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

int n, m;

bool isPossible(const int &num, const vector<int> &marble){

	int num_group = 1;
	int sum = 0;
	for (int i = 0; i < n; i++){
		int cur = marble[i];
		if (cur > num) return false;
		if (sum + cur <= num)
			sum += cur;
		else{
			sum = cur;
			num_group++;
		}
		if (num_group > m)
			return false;
	}


	return true;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int ans = INT_MAX;
	cin >> n >> m;
	vector<int> marble(n);
	for (int i = 0; i < n; i++)
		cin >> marble[i];
	int left = 1, right = 300 * 100;
	while (left <= right){
		int num = (left + right) / 2;
		if (isPossible(num, marble)){
			right = num - 1;
			ans = min(num, ans);
		}
		else
			left = num + 1;
	}
	cout << ans << endl;
	int before = 0;
	int sum = 0;
	for (int i = 0; i < n; i++){
		int cur = marble[i];
		if (sum + cur <= ans)
			sum += cur;
		else{
			cout << i - before << " ";
			sum = cur;
			before = i;
		}
	}
	cout << n - before << endl;
}