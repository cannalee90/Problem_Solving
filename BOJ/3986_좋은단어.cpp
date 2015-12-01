#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

int main() {
    int ans = 0, n;
    cin >> n;
    
    while(n--) {
        string str;
        cin >> str;
        stack<char> st;
        for(int i = 0; i < str.size(); i++) {
            char cur = str[i];
            if(!st.empty() && cur == st.top()) {
                while(!st.empty() && cur == st.top())
                    st.pop();
            }else {
                st.push(cur);
            }
        }
        if(st.empty())
            ans++;
    }
    cout << ans << endl;
}
