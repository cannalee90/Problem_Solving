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
int t;
ll n, l, w, h;


bool isPossible(double A){
	ll t1 = (double)l / A;
	ll t2 = (double)w / A;
	ll t3 = (double)h / A;
	if (t1 * t2 * t3 >= n)
		return true;
	else
		return false;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	double ans = 0;
	cin >> n >> l >> w >> h;
	ll T = 100;
	double left = 0, right = min(l , min(w, h));
	while (T--){
		double A = (left + right) / 2.0;
		if (isPossible(A)){
			ans = A;
			left = A;
		}
		else
			right = A;
	}
	printf("%.11lf\n", ans);
}