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
	string d2;
	vector<string>result;
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> d1;
		d2 = d1;
		next_permutation(d1.begin(), d1.begin() + d1.length());
		if(d1 > d2)
			cout<< d1 << endl;
		else
			cout << d2 << endl;

	}
}