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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<long long > data;
	priority_queue < ll > pq;

	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		pq.push(t1);
	}
	sort(data.begin(), data.end());
	bool f = false;
	long long width; 
	long long ans = 0;
	while (pq.size() > 1){
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		if (a == b || a == b + 1){
			if (f == false){
				width = b;
				f = true;
			}
			else{
				ans += width * b;
				f = false;
			}
		}
		else{
			pq.push(b);
		}
	}
	cout << ans << endl;
}