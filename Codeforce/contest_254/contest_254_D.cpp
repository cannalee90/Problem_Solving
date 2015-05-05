#include <iostream>
#include <limits.h>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;

ll n, d, x;

ll getNextX() {

	x = (x * 37 + 10007) % 1000000007;
	return x;
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> d >> x;
	for (int i = 0; i < n; i = i + 1){
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (int i = 0; i < n; i++){
		cout << getNextX() % (i + 1) << endl;
	}
}