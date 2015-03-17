#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define INF 900000000

using namespace std;

typedef long long ll;



int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll n, k;
	ll total = 0;
	ll loop = 1;
	cin >> n >> k;
	while(n)
	{
		if( n > (9 * pow(10, (double)loop- 1)))
		{
			total += loop * 9 * pow(10, (double)loop - 1);
			n -= 9 * pow(10, (double)loop - 1);
		}
		else
		{
			total += loop * n;
			break;
		}
		loop++;
	}
	ll p = k;

	if(total < k)
	{
		cout << "-1";
	}
	else
	{
		loop = 1;
		while(k)
		{
			string result = "";
			ll ND = (9 * pow(10, (double)loop- 1));
			if( k > ND * loop)
			{
				k -= loop * ND;
			}
			else
			{
				ND = pow(10, (double)loop - 1);
				for(int i = ND; i<=p; i++)
				{
					string a = to_string((ll)i);
					result += a;
					if(k == loop)
					{
						k = 0;
						break;
					}
					if(k < loop)
						break;


				}
				reverse(result.begin(), result.end());
				cout << result[k] << endl;
				return 0;
			}
			loop++;
		}
	}
}
