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


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string data;
	stack<char> st;
	cin >> data;
	for (int i = 0; i < data.size(); i++){
		if (st.empty()){
			st.push(data[i]);
		}
		else{
			if (data[i] == st.top())
				st.pop();
			else
				st.push(data[i]);
		}
	}
	if (st.empty()){
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
}
