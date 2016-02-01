//
// Created by  이강호 on 2016. 2. 2..
//


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long > vl(n);
    long long sum = 0, partial = 0;
    for(int i = 0; i < n; i++) {

        scanf("%lld", &vl[i]);

    }
    sort(vl.rbegin(), vl.rend());
    for(int i = 0;i < vl.size(); i++)  {
        long long num = vl[i];
        sum += (num) * ((n * 2LL) - ((i) * 2LL) - 1);
        sum -= (num) * ((i * 2LL) + 1LL);
    }
    cout << sum << endl;
}
