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

	int n, t, m;

	int main(){
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		cin >> n;
		vector<int> vi(n);
		stack <int> st, rst;
		for (int i = 0; i < n; i++)
			cin >> vi[i];
		st.push(-1);
		rst.push(-1);
		for (int i = 0; i < n; i++){
			if (st.top() < vi[i]) st.push(vi[i]);
			if (rst.top() < vi[n - 1 - i]) rst.push(vi[n - 1 - i]);
		}
		cout << st.size() - 1 << endl << rst.size() - 1 <<endl;
	}

