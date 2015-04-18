#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	set< string > list;
	cin >> n;
	while (n--){
		string name;
		string record;
		cin >> name >> record;
		if (record[0] == 'e')
			list.insert(name);
		else
			list.erase(name);
	}
	set< string >::reverse_iterator itor = list.rbegin();
	while (itor != list.rend()){
		cout << *itor << endl;
		itor++;
	}
}