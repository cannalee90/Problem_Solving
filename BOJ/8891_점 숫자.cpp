#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF
const long long  hash_value =  1000000000000000007;
                               

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n;
	cin >> t;
	while(t--)
	{
		int a , b;
		int flag =0;
		int x = 0, y = 0;
		scanf("%d %d", &a , &b);
		int cnt = 0;
		for(int i = 1; cnt <= 100000; i++)
		{
			for(int j = 1; j<=i; j++)
			{
				cnt++;
				if(cnt == a)
				{
					x += j;
					y += i - j + 1;
					flag++;
				}
				if(cnt == b)
				{
					x += j;
					y += i - j + 1;
					flag++;
				}
				if(j == x && i - j + 1 == y && flag == 2)
				{
					cout << cnt << endl;
					flag++;
					break;
				}
			}
			if(flag == 3) break;
		}
	}
}
