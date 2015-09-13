#include <iostream>
#include <fstream>
#include <cstring>
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

int board[2001][2001];
int lleft[2001], rright[2001];
int n;


int sol(int l, int r){
    int &ret = board[l][r];
    if(l == n + 1 || r == n + 1) return 0;
    if(ret != -1) return ret;
    ret = max(sol(l + 1, r + 1), sol(l + 1, r));
    if(rright[r] < lleft[l])
        ret = max(ret, sol(l, r + 1) + rright[r]);
    return ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    memset(board, -1, sizeof(board));
    cin >> n;   
    

    for(int i = 1; i <=n; i++)
        cin >> lleft[i];
    for(int i = 1; i <=n; i++)        
        cin >> rright[i];
    cout << sol(1, 1) << endl;
}