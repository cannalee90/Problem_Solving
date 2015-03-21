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
	long long n;
	vector<long long> data;
	cin >> n;
	for (long long i = 0; i < n; i++){
		long long t1;
		cin >> t1;
		data.push_back(t1);
	}
	sort(data.begin(), data.end());

	long long ans_1 = data[0];
	long long ans_2 = data[1];
	long long ans_3 = data[data.size() - 1];
	long long ans = abs(ans_1 + ans_2 + ans_3);
	for (long long i = 0; i < n - 2; i++){
		long long pre = data[i];
		long long left = i + 1;
		long long right = data.size() - 1;
		long long sum = pre + data[left] + data[right];
		while (1){
			if (abs(sum) < ans){
				ans = abs(sum);
				ans_1 = pre;
				ans_2 = data[left];
				ans_3 = data[right];
			}
			if (sum > 0){
				sum -= data[right--];
				sum += data[right];
			}
			else if (sum < 0){
				sum -= data[left++];
				sum += data[left];
			}
			if (sum == 0){
				cout << pre << " " << data[left] << " " << data[right];
				return 0;
			}
			if (left == right) break;

		}
	}
	cout << ans_1 << " " << ans_2 << " " << ans_3 << endl;
}