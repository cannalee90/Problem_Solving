#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <map>
#include <unistd.h>
#define INF 987654321
typedef long long ll;

using namespace std;

int delTrail(int num) {
    while(!(num % 10)) {
        num /= 10;
    }
    return num;
}

int getA(int num) {
    string str = to_string(num);
    if(num % 10 == 5)
        return (int)str.size() * 2 - 1;
    else
        return (int)str.size() * 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n < 10) {
            puts("not absurd");
            continue;
        }
        int lower = ceil(n * 0.95); //range 때문에 많이 틀림.. 이런식으로 range를 지정해줘야함.
        int upper = floor(n * 1.05);
        bool isAbsurb = false;
        int num = getA(delTrail(n));
        for(int i = lower; i <= upper; i++) {
            if(i % 10 == 5) {
                int cur = getA(delTrail(i));
                if(cur < num)
                    isAbsurb = true;
            }
            else if(i % 10 == 0) {
                int cur = getA(delTrail(i));
                if(cur < num)
                    isAbsurb = true;
                i /= 10;
                upper /= 10;
            }
        }
        if(!isAbsurb)
            puts("not absurd");
        else
            puts("absurd");
    }
}

