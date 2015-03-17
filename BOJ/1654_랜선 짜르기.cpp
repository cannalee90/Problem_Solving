#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

int n, m;
int ans = INT_MIN;

vector<int> data;

int get_number(int pivot){
	int lan = 0;
	for (int i = 0; i < n; i++)	{
		lan += data[i] / pivot;
	}
	return lan;

}

void binary_search(int left, int right){
	int pivot = (left + right) / 2;
	int lan_piece = get_number(pivot);
	if (lan_piece >= m && ans < pivot)
		ans = pivot;
	if (left == right || right == pivot) return;
	if (lan_piece >= m)
		binary_search(pivot + 1, right);
	if (lan_piece < m)
		binary_search(left, pivot - 1);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int mmax = INT_MIN;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		data.push_back(t1);
		mmax = max(mmax, t1);
	}
	binary_search(1, mmax);
	cout << ans << endl;
}
