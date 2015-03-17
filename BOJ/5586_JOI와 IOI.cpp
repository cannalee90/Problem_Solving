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


typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	string t1;
	int ni = 0;
	int ji = 0;
	cin >> t1;
	string JOI = "JOI";
	string IOI = "IOI";
	for(int i = 0; i<t1.length(); i++)
	{
		if(t1.substr(i, 3) == JOI)
		{
			ji++;
		}
		if(t1.substr(i, 3) == IOI)
		{
			ni++;
		}
	}
	cout << ji << endl << ni << endl;
}
