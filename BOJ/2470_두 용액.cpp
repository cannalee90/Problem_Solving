#include <iostream>
#include <limits.h>
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

typedef long long ll;

using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	vector<int> data;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		data.push_back(t1);
	}
	int ans_1 = data[0];

	sort(data.begin(), data.end());
	int left = 0;
	int right = data.size() - 1;
	int sum = data[left] + data[right];
	int ans = abs(data[left] + data[right]);
	int ans_2 = data[left];
	int ans_3 = data[right];
	while (right - left > 1){
		if (sum > 0){
			sum -= data[right--];
			sum += data[right];
		}
		else if (sum < 0){
			sum -= data[left++];
			sum += data[left];
		}
		if (sum == 0){
			cout << data[left] << " " << data[right] << endl;
			return 0;
		}
		if (abs(sum) < ans){
			ans = abs(sum);
			ans_2 = data[left];
			ans_3 = data[right];
		}
	}
	cout << ans_2 << " " << ans_3 << endl;
}