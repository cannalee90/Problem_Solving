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
		freopen("\input.txt", "r", stdin);
	#endif
		string data;
		string ans;
		getline(cin, data);
		stack<char> st;
		for (int i = 0; i < data.size(); i++){
			if (data[i] == ' ') continue;
			char cur = data[i];
			if (cur >= 'A' && cur <= 'Z'){
				ans += cur;
			}
			else if (!st.empty()){
				if (cur == '('){
					st.push(cur);
					continue;
				}
				else if (cur == ')'){
					while (st.top() != '('){
						ans += st.top();
						st.pop();
					}
					st.pop();
				}
				else if (cur == '+'){
					while (st.top() != '('){
						ans += st.top();
						st.pop();
						if (st.empty())
							break;
					}
					st.push(cur);
				}
				else if (cur == '-'){
					while (st.top() != '('){
						ans += st.top();
						st.pop();
						if (st.empty())
							break;
					}
					st.push(cur);
				}
				else if (cur == '/'){
					while (st.top() == '*' || st.top() == '/'){
						ans += st.top();
						st.pop();
						if (st.empty())
							break;
					}
					st.push(cur);
				}
				else if (cur == '*'){
					while (st.top() == '*' || st.top() == '/'){
						ans += st.top();
						st.pop();
						if (st.empty())
							break;
					}
					st.push(cur);
				}
			}
			else
				st.push(cur);
		}
		while (!st.empty()){
			if(st.top() != '(')
				ans += st.top();
			st.pop();
		}
		cout << ans << endl;
	}