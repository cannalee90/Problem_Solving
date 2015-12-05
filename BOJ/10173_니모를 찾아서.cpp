#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 987654321
typedef long long ll;

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    while(true) {
        
        string str;
        getline(cin, str);
        if(str == "EOI") break;
        bool isNemo = false;
        for(int i = 0; i < str.size() - 3; i++) {
            char cur = str[i];
            char cur1 = str[i + 1];
            char cur2 = str[i + 2];
            char cur3 = str[i + 3];
            if(tolower(cur) == 'n' && tolower(cur1) == 'e' && tolower(cur2) == 'm' && tolower(cur3) == 'o')
                isNemo = true;
        }
        if(isNemo)
            cout << "Found" << endl;
        else
            cout << "Missing" << endl;
    }
}
