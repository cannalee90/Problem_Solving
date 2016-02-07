//
// Created by  이강호 on 2016. 2. 7..
//

#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cmath>
#include <algorithm>

typedef long long ll;

#define INF 987654321
using namespace std;


int main() {
    int n, m;
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    string str;
    cin >> str;
    vector<char> st;
    for(char cur : str) {
        st.push_back(cur);
        int len = st.size();
        while(st.size() >= 2 && st[len-1] == ')' && st[len-2] == '(') {
            st.pop_back();
            st.pop_back();
            len -= 2;
        }
    }
    cout << st.size() << endl;
}
