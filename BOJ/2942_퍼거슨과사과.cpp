#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>
#include <cmath>
   
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
	int small;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    L = lcm(n, m);
	int cnt = 1;
	small = sqrt((double)L);
    for(int i = 1; i<=small; i++)
    {
        if(n % i == 0 && m % i == 0)
        {
			if(i != (L / i))
			{
				printf("%d %d %d\n", i, n /i, m / i);
				printf("%d %d %d\n", (L / i), n /(L / i),m/(L/i));
			}
			else
			{
				printf("%d %d %d\n", i, n /i, m / i);

			}
        }
    }
	
}