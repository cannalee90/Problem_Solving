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
#include <cmath>

typedef long long ll;
using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));


int main()
{
    freopen("input.txt", "r", stdin);
    int n, ans = 0;
    cin >> n;
    vector<pair<int, int > > vp(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    st.push(0);
    for(int i = 0; i < n; i++){
        int num = vp[i].second;
        if(st.empty())
            st.push(num);
        else{
            while(!st.empty() && st.top() > num){
                st.pop();
                ans++;
            }
            if(num == st.top())
                continue;
            else
                st.push(num);
        }
    }
    cout << ans + st.size() - 1 << endl;
}