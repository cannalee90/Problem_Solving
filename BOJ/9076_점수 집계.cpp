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

   
using namespace std;

void input(list<int> &d1)
{
	int temp;
	vector<int> d2;
	for(int i = 0; i<5; i++)
	{
		cin >> temp;
		d2.push_back(temp);
	}
	sort(d2.begin(), d2.end());
	for(int i = 0; i<5; i++)
	{
		d1.push_back(d2[i]);
	}
}

int getTotal(list<int> d1)
{
	int temp = 0;
	while(!d1.empty())
	{
		temp += d1.front(); 
		d1.pop_front();
	}
	return temp;
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for(int i = 0 ; i<n; i++)
	{
		list<int> d1;
		input(d1);
		d1.pop_back();
		d1.pop_front();
		(abs(d1.back() - d1.front()) >= 4) ? cout << "KIN" << endl: cout << getTotal(d1)<< endl;
	}
}
