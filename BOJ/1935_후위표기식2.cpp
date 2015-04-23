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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	stack<double> st;
	string data;
	vector<double> values(30, 0);
	double ans = 0.0;
	cin >> n;
	cin >> data;
	for (int i = 0; i < n; i++)
		cin >> values[i];
	for (int i = 0; i < data.size(); i++){
		char cur = data[i];
		if (cur >= 'A' && cur <= 'Z'){
			st.push(values[cur - 'A']);
		}
		else{
			double operand_1 = st.top();
			st.pop();
			double operand_2 = st.top();
			st.pop();
			if (cur == '+')
				st.push(operand_2 + operand_1);
			else if (cur == '-')
				st.push(operand_2 - operand_1);
			else if (cur == '*')
				st.push(operand_2 * operand_1);
			else
				st.push(operand_2 / operand_1);
		}
	}
	printf("%.2lf\n", st.top());
}