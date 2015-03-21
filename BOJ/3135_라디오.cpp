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
#include <functional>

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int des, start;
	int n;
	cin >> start >> des;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(abs(des - start));
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		pq.push(abs(m - des) + 1);
	}
	cout << pq.top() << endl;
}
