#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
    
using namespace std;
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    int n;
    vector<int> d1(20);
    d1[0] = 4;
    cin >> n;
    cout << (long long)pow((double)(pow((double)2, n) + 1), 2) << endl;
}