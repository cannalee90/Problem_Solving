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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int here;
	int there;
	int ans = 0;
	cin >> here >> there;
	here--;
	there--;
	if (here > there) swap(here, there);
	while ((here / 4) != (there / 4)){
		ans++;
		here += 4;
		
	}
	cout << ans + abs(here - there) << endl;
}