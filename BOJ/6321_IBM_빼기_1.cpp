#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
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
	cin >> n;
	for(int k = 0; k<n; k++){
		string a; 
		cin >> a;
		printf("String #%d\n", k + 1);
		for (int i = 0; i < a.size(); i++){
			if (a[i] != 'Z')
				printf("%c", a[i] + 1);
			else
				cout << 'A';
		}

		cout << endl << endl;
	}
}
