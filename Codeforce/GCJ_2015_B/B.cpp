#include <stdio.h>
#include <queue>
#include <string.h>
#define MAX	1000010

using namespace std;

typedef long long ll;

int T;
ll n, dist[MAX], p[MAX];

ll getReverse(ll num) {
	ll ret = 0;
	while (num) {
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

ll getLastNumber(ll num) {
	ll ret = 0;
	while (num) {
		ret *= 10;
		ret += 9;
		num /= 10;
	}
	return ret;
}

ll getLengthNumber(ll num) {
	ll ret = 0;
	while (num) {
		ret++;
		num /= 10;
	}
	return ret;
}

ll getFrontHalfNumber(ll num) {
	ll tailHalfLength = getLengthNumber(num) / 2;
	while (tailHalfLength--) num /= 10;
	return num;
}

ll greedy() {
	if (n <= 10) return n;
	ll cur = 10, ret = 10;
	while (cur<n) {
		if (getLengthNumber(cur)<getLengthNumber(n)) {
			ll lastNumber = getLastNumber(cur);
			ll lastNumberLength = getLengthNumber(lastNumber);
			if (lastNumberLength & 1) {
				ll repeat = lastNumberLength / 2 + 1, sum = 0;
				while (repeat--) {
					sum *= 10;
					sum += 9;
				}
				cur += sum;
				cur = getReverse(cur);
				ret += sum + 1;
			}
			else {
				ll repeat = lastNumberLength / 2, sum = 0;
				while (repeat--) {
					sum *= 10;
					sum += 9;
				}
				cur += sum;
				cur = getReverse(cur);
				ret += sum + 1;
			}
			ret += lastNumber - cur + 1;
			cur = lastNumber + 1;
		}
		else {
			ll frontNumber = getFrontHalfNumber(n);
			if (getReverse(cur + getReverse(frontNumber))>n) frontNumber--;
			frontNumber = getReverse(frontNumber);
			ret += frontNumber;
			cur += frontNumber;
			if (getReverse(cur)>cur) {
				cur = getReverse(cur);
				ret++;
			}
			ret += n - cur;
			cur = n;
		}
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("result.txt", "w+", stdout);

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", t, greedy());
	}
}