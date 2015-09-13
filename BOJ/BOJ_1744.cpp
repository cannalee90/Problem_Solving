#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <limits.h>
#include <cmath>
 
typedef long long ll;
using namespace std;
 
#define pb push_back
#define mp(a, b) make_pair((a), (b))
int main()
{
    

    ll n;
    ll zero_cnt = 0;
    ll ans = 0;
    cin >> n;
    
    priority_queue<ll, vector<ll>, less<ll> > pos;
    priority_queue<ll, vector<ll>, greater<ll> >neg;

    for(ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        if(num > 0)
            pos.push(num);
        else if(num <= 0)
            neg.push(num);
    }
    while(pos.size() > 1) {
        ll a = pos.top();
        pos.pop();
        ll b = pos.top();
        pos.pop();
        if(a == 1) {
            ans += 2;
        }
        else if (b == 1) {
            ans += (a + b);
        }
        else { 
            ans += a * b;
        }
    }

    if(pos.size() == 1)
        ans += pos.top();

    while(neg.size() > 1) {
        ll a = neg.top();
        neg.pop();
        ll b = neg.top();
        neg.pop();
        ans += a * b;
    }

    if(neg.size() == 1)
        ans += neg.top();

    cout << ans << endl;
}