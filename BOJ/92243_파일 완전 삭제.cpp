	#include <iostream>
	#include <fstream>
	#include <string>
	#include <string.h>
	#include <queue>
	#include <stdio.h>
	#include <algorithm>
	#include <vector>
	#include<iomanip>
	#include <stack>
   
	using namespace std;

	int main()
	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif
		int n;
		string before;
		string after;
		cin >> n;
		cin >> before;
		for(int t = 0; t<n; t++)
		{
			for(int i = 0; i<before.length(); i++)
			{
				if(before[i] == '0') before[i] = '1';
				else if(before[i] == '1') before[i] = '0';
			}
		}
		cin >> after;
		if(before == after) cout << "Deletion succeeded" << endl;
		else cout << "Deletion failed" << endl;
	}
