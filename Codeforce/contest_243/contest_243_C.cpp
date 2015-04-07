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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	unsigned m;
	ll ans = LONG_MIN;
	cin >> n >> m;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];
	for (int k = 0; k < n; k++){
		for (int i = k; i < n; i++){
			priority_queue <int, vector<int>, greater<int> > pq_1;
			priority_queue <int, vector<int>, less<int> > pq_2;
			ll sum = 0;
			for (int j = 0; j < n; j++){
				if (j <= i && j >= k){
					pq_1.push(data[j]);
					sum += data[j];
				}
				else{
					pq_2.push(data[j]);
				}
			}
			int limit = min(pq_1.size(), min(pq_2.size(), m));
			ans = max(ans, sum);
			for (int i = 0; i < limit; i++){
				sum += pq_2.top() - pq_1.top();
				pq_1.pop();
				pq_2.pop();
				ans = max(ans, sum);
			}
		}
	}
	cout << ans << endl;
}
