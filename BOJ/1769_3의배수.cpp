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
	string d1;
	int cnt = 0;
	int total = 0;
	cin >> d1;
	if(d1.length() == 1)
	{
		total += d1[0] -'0';
	}
	while(d1.length()>1)
	{

		for(int i = 0; i<d1.length(); i++)
		{
			total += d1[i] - '0';
		}
		cnt++;
		if(total < 10) break;
		d1 = "";
		while(total > 0)
		{
			d1.insert(d1.begin(),total % 10+ '0');
			total = total / 10;
		}
	}
	cout << cnt << endl;
	if(total % 3 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}