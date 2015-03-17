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
	int d1[3][2];
	int c, b, a;
	int total = 0;
	cin >> c >> b >> a;
	for(int i = 0; i<3; i++)
	{
		cin >> d1[i][0] >> d1[i][1];
	}
	for(int i = 1; i<=100; i++)
	{
		int count = 0;
		for(int j = 0; j<3; j++)
		{
			if(d1[j][0] < i && d1[j][1] >= i)
			{
				count ++;
			}
		}
		if(count == 1) total += c;
		if(count == 2) total += b;
		if(count == 3) total += a;
	}
	
	cout << total << endl;
}

//1 2 3 4 5 6 7 8
//-----------
//    -----
//  -------------

//1-2 5
//2-3 3
//3-4 1
//4-5 1
//5-6 3
//6-7 5
//7-8 5