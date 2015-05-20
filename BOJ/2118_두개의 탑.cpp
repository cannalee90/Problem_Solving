#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

const int M = 50001;

int n, m, t;
int data[M];
ll sum;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
		sum += data[i];
	}
	int begin = 0;
	int end = 0;
	ll temp = 0;
	ll ans = 0;
	while (1){
		while (sum - temp > temp){
			temp += data[end++];
			end %= n;
			ans = max(ans, min(sum - temp, temp));
		}
		temp -= data[begin];
		ans = max(ans, min(sum - temp, temp));
		begin++;
		begin %= n;
		if (begin == 0) break;
	}
	cout << ans << endl;
}