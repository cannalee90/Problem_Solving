#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 10000007
#define INF 10000009
#define INF 900000000
 
 
typedef long long ll;
using namespace std;
 
int DP[1100][1100];
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    string a, b;
    cin >> a >> b;
 
    a.insert(0,"0");
    b.insert(0,"0");
    for(int i = 1; i<b.size(); i++)
    {
        int idx = 1;
        for(int j = 1; j<a.size(); j++)
        {
            int t1 = DP[i-1][j-1];
            if(a[j] == b[i]) t1++;
            int t2 = max(DP[i-1][j], DP[i][j-1]);
            DP[i][j] = max(t1, t2);
        }
    }
    cout << DP[b.size()-1][a.size()-1] << endl;
}