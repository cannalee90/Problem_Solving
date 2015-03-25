#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
	long long a, b;
	long long s = 0;
	cin >> a >> b;
	while (b > 0){
		s += a / b;
		a %= b;
		if(b > a)
			swap(a, b);
	}
	cout << s << endl;
}