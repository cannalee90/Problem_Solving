#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>
   
using namespace std;
  
 
int lcm(int a, int b)
{
    int temp;
    if(a < b) swap(b,a);
    while(a != 0)
    {
        temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}
 
int main()
{
    int n;
    int m;
    int L;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    L = lcm(n, m);
    for(int i = 1; i<=sqrt(L); i++)
    {
        if(n % i == 0 && m % i == 0)
        {
            printf("%d %d %d\n", i, n /i, m / i);
        }
    }
}