#include <iostream>
#include <utility>
#include <limits.h>
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

ll get_coor(ll coor, ll limit, ll time){
	coor = coor + time;
	if ((coor / limit) % 2 == 0){
		return coor % limit;
	}
	else{
		return limit - (coor % limit);
	}
}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll x_l, y_l;
	ll x, y;
	ll time;
	cin >> x_l >> y_l;
	cin >> x >> y;
	cin >> time;
	cout << get_coor(x, x_l, time) << " "<< get_coor(y, y_l, time) << endl;
}