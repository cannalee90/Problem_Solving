#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>

#define INF 987654321
typedef long long ll;

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    for(char cur : str) {
        if(cur >= 'A' && cur <= 'Z')  {
            cur = (cur + 13) % ('Z' + 1);
            if(cur < 'A') cur += 'A';
        }
        else if(cur >= 'a' && cur <= 'z') {
            cur = (cur + 13) % ('z' + 1);
            if(cur < 'a') cur += 'a';
        }
        cout << cur;
    }
    puts("");
}

