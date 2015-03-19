#include <iostream>
#include <functional>

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

using namespace std;


long long n, m, k;


int main()
{

#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	long long ans = 0;
	long long comp = 0;

	priority_queue<pair<int, int>  > pq;

	cin >> n;
	if (n == 1) {
		cout << "0" << endl; return 0;
	}
	cin >> comp;
	

	for (long long i = 1; i < n; i++){
		long long t1;
		cin >> t1;
		pq.push(make_pair(t1, i));
	}

	while (1){
		if (comp > pq.top().first) 
			break;
		ans ++;
		comp++;
		int t_1 = pq.top().first;
		int t_2 = pq.top().second;
		pq.pop();
		pq.push(make_pair(--t_1, t_2));
	}
	cout << ans << endl;
	return 0;
}