#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

#define INF 900000000

using namespace std;

typedef long long ll;



int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	ll t, n;
	ll t1,t2;
	ll target;

	cin >> t;
	while(t--)
	{
		
		list < ll > priority;
		list < ll > number;
		list < ll >::iterator itor;
		cin >> n >> target;
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			priority.push_back(t1);
			number.push_back(i);
		}
		int cnt = 1;
	
		while(!priority.empty())
		{
			int d = 0;
			for(itor = priority.begin(); itor != priority.end(); itor++)
			{
				if(priority.front() < *itor)
				{
					priority.push_back(priority.front());
					priority.pop_front();
					number.push_back(number.front());
					number.pop_front();
					break;
				}
			}
			if(itor == priority.end() && number.front() == target)
			{
				cout << cnt << endl;
				break;
			}
			else if(itor == priority.end())
			{
				cnt++;
				priority.pop_front();
				number.pop_front();
			}

		}
	}
}
