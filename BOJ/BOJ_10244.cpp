
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int> vi(n), ans;
        set<int> cnt;
        bool visited[101];
        for(int i = 0; i < n; i++)
            cin >> vi[i];

        for(int i = 0; i < n; i++){
            memset(visited, 0, sizeof(visited));
            int num = vi[i];
            for(int j = 0; j< ans.size(); j++){
                int G = gcd(num, ans[j]);
                visited[G] = true;
            }
            ans = vector<int>();
            for(int j = 1; j <= 100; j++){
                if(visited[j]){
                    ans.push_back(j);
                    cnt.insert(j);
                }
            }
            ans.push_back(vi[i]);
            cnt.insert(vi[i]);
        }
        cout << cnt.size() << endl;
     }
}
