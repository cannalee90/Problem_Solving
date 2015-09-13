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

bool isDivided(const string &str, int num){
    int ret = 0;
    for(int i = 0 ; i < str.size(); i ++){
        ret *= 10;
        ret += str[i] - '0';
        ret %= num;
    }
    return ret == 0;
}

int main()
{
    string str;
    int n;
    cin >> str >> n;
    vector<bool> Prime(n + 1, false);
    for(int i = 2; i<n; i++){
        if(!Prime[i]){
            if(isDivided(str, i)){
                cout << "BAD" <<  endl;
                cout << i << endl;
                return 0;
            }
            for(int j = i; j<n; j += i)
                Prime[j] = true;
        }
    }
    cout << "GOOD" << endl;
}
    

    