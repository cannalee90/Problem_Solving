#include <iostream>
#include <limits.h>
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

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int w, h;
	cin >> n >> w >> h;
	w *= w;
	h *= h;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		if (t * t > w + h){
			cout << "NE" << endl;
		}
		else{
			cout << "DA" << endl;
		}
	}
}