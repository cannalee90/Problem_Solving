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
	long double n;
	long double a;
	long long ans = 0;
	cin >> n;
	for(int i = 1; ; i++)
	{
		a = pow(5 * 1.0, i);
		if(n / a <= 1) break;
		else ans += n / a;
	}
	cout << ans + 1 << endl;
}