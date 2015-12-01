#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		if (n == 1) {
			printf("1\n");
			continue;
		}
		long long left = 1, right = 987654321;
		long long ans = 1;
		while (left <= right) {
			long long mid = (left + right) / 2LL;
			if ((mid +1) * mid >= n * 2) {
				ans = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}
		if ((ans +1) * ans == n * 2)
			cout << ans  << endl;
		else
			cout << ans - 1 << endl;
	}
}