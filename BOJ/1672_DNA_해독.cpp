#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

int n;

int get_number(char cur){
	if (cur == 'A')
		return 0;
	else if (cur == 'G')
		return 1;
	else if (cur == 'C')
		return 2;
	else
		return 3;
}

char get_char(int cur){
	if (cur == 0)
		return 'A';
	else if (cur == 1)
		return 'G';
	else if (cur == 2)
		return 'C';
	else
		return 'T';
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int table[4][4] = { { 0, 2, 0, 1 },
						{ 2, 1, 3, 0 },
						{ 0, 3, 2, 1 },
						{ 1, 0, 1, 3 } };
	cin >> n;
	string str;
	cin >> str;
	while (str.size() != 1){
		int t_1 = get_number(str.back());
		str.pop_back();
		int t_2 = get_number(str.back());
		str.pop_back();
		str.push_back(get_char(table[t_1][t_2]));
	}
	cout << str << endl;
}

