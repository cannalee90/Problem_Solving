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
	unsigned long long  test, t1;
	cin >> test;
	while(test--)
	{
		long long cnt = 0;
		unsigned long long total = 0;
		vector<long long>d1;
		d1.push_back(0);
		while(1)
		{
			cin >> t1;
			if(t1 == 0) break;
			d1.push_back(t1);
			cnt++;
		}
		sort(d1.begin(), d1.end());
		for(int i = 1; i<=cnt; i++)
		{
			total += (2)  * pow((double)d1[i],(double)cnt - i + 1);
		}
		if(total > 5 * pow((double)10, 6))
		{
			cout <<"Too expensive" << endl;
		}
		else
		{
			cout << total << endl;
		}
	}
}